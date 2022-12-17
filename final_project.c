#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//----------------------------------------------------------------宣告
int area[5] = {0};
int areasitutaion[6];
int dollars = 100,isc = 50,ipc = 100,dollarsum = 0,minutes = 15,price = 30; // orgin
int speedbooster = 0,pricebooster = 0,areabooster = 0; // boost count
int freechoice = 0;
int n=3,lottery[100][100],lotteryprice = 500,lotterynspace = 0;
int lotterynumber,cell;
int temp,temp2;
int boostersum = 0,boosterqueue[15],boosterslots;
int mapsituation[8][8],playerlocation;
int tasksituation[5],mission[5];
int speedboosteropen = 0,priceboosteropen = 0,areaboosteropen = 0; // boost open close
/*
t1 賣50跟熱狗
t2 開任一booster3次
t3 將做熱狗的速度提升到滿
t4 抽10次獎
t5 在地圖上移動20次
*/
void mapinitialization();
void begin();
int booster(int *s,int *p, int *a);
void boosterchoose();
void actions(int isc,int ipc);
void actionsagain(int i);
void actionsdo(int i);
void boostercheck();
void areacheck();
void end();
int lotterybuild();
int lotterychoose();
void boosterjudge();
int mapsystem();
void eventcheck();
int missioncheck();
int missioncomplete();
//----------------------------------------------------------------函式
void mapinitialization(){
    for(int i = 0;i < 8; i++){
        for(int j = 0;j < 8; j++){
            mapsituation[i][j] = 0;
        }
    }
    mapsituation[0][0] = 1; // 1 == P(player)
    playerlocation = 0;
    for(int i = 2;i <= 4; i++){
        temp = rand()%64;
        if(mapsituation[temp/8][temp%8]!=0){
            i--;
            continue;
        }
        mapsituation[temp/8][temp%8] = i; // 2 == M(Money) 3 == B(Booster) 4 == T(Task)
    }
}
void begin(){
    printf("Chop chop, It's dawn.\n");
    printf("You have %d dollars.\n",dollars);
    printf("You need %d minutes to make a hotdog.\n",minutes);
    printf("The price of a hotdog is $%d.\n",price);
    printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n",speedbooster,pricebooster,areabooster);
    printf("Your slots of boosters are %d.\n",boosterslots);
    switch(boosterqueue[0]){
        case 1:
            printf("The oldest booster is speedbooster.");
            break;
        case 2:
            printf("The oldest booster is pricebooster.");
            break;
        case 3:
            printf("The oldest booster is areabooster.");
            break;
        default:
            printf("You have no booster now.");
    }
}
int booster(int *s,int *p, int *a){ // booster choose function
    int i;
    scanf("%d", &i);
    switch(i){
        case 1:
            if(*s == 1){
                *s = 0;
            }
            else{
                *s = 1;
            }
            break;
        case 2:
            if(*p == 1){
                *p = 0;
            }
            else{
                *p = 1;
            }
            break;
        case 3:
            if(*a == 1){
                *a = 0;
            }
            else{
                *a = 1;
            }
            break;
        case 4:
            return 0;
        default:
            return 2;
    }
    return 1;
}
void boosterchoose(){
    int temp;
    printf("Open/Close boosters:\n");
    speedboosteropen?printf("  [1] Speed booster (now open)\n"):printf("  [1] Speed booster (now close)\n");
    priceboosteropen?printf("  [2] Price booster (now open)\n"):printf("  [2] Price booster (now close)\n");
    areaboosteropen?printf("  [3] Area  booster (now open)\n"):printf("  [3] Area  booster (now close)\n");
    printf("  [4] Finish\n");
    printf("Enter the number(s): ");
    temp = booster(&speedboosteropen,&priceboosteropen,&areaboosteropen);
    if(temp == 2){
        printf("Invalid input!!!!\n");
        boosterchoose();
    }
    else if(temp != 0){
        boosterchoose();
    }
}
void actions(int isc,int ipc){ // actions choose
    printf("Actions you can take for each area:\n");
    printf("  [1] Sell the hotdogs\n");
    printf("  [2] Improve your cooking speed\n");
    printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", isc,isc*2 ,isc*4 ,isc*8 );
    printf("  [3] Improve your hotdog flavor\n");
    printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", ipc, ipc*2, ipc*4, ipc*8);
    printf("Enter the number(s): ");
    scanf("%d %d %d %d",&area[0],&area[1],&area[2],&area[3]);
    for(int i=0;i<4;i++){
        if(area[i] != 1 && area[i] != 2 && area[i] != 3){
            area[i] = 0;
        }
    }
    for(int i = 0;i<4;i++){
        if(area[i] == 0){
            actionsagain(i);
        }
    }


}
void actionsagain(int i){ // actions invalid,choose again
    printf("Invalid input!!!!\n");
    printf("Actions you can take at Area %d:\n", i+1);
    printf("  [1] Sell the hotdogs\n");
    printf("  [2] Improve your cooking speed\n");
    printf("  [3] Improve your hotdog flavor\n");
    printf("Enter the number(s): ");
    scanf("%d",&area[i]);
    if(area[i] != 1 && area[i] != 2 && area[i] != 3){
        actionsagain(i);
    }
}
void actionsdo(int i){ // do area actions
    switch (area[i]){
        case 1:
            areasitutaion[i] = 0;
            sellhotdog:
            dollars += (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1);
            dollarsum += (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1);
            if(speedboosteropen){
                speedboosteropen = 2; // 開啟過了
            }
            if(priceboosteropen){
                priceboosteropen = 2; //開啟過了
            }
            if(tasksituation[0] == 1){
                mission[0]-=(180/minutes)*(speedboosteropen?2:1);
            }
            break;
        case 2:
            if(dollars<isc){
                areasitutaion[i] = 1;
                goto sellhotdog;
            }
            else{
                if(minutes==1){
                    areasitutaion[i] = 2;
                    mission[2] = 0; 
                    goto sellhotdog;
                }
                else{
                    areasitutaion[i] = 3;
                    minutes -=1;
                    dollars -=isc;
                    isc *= 2;
                    break;
                }
            }
            break;
        case 3:
            if(dollars<ipc){
                areasitutaion[i] = 1;
                goto sellhotdog;
            }
            else{
                areasitutaion[i] = 4;
                price += 10;
                dollars -= ipc;
                ipc *= 2;
                break;
            }
            break;
    }
    if(i == 3){
        if(areaboosteropen){
                dollars += (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1);
                dollarsum += (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1);
                areabooster -= 1;
                for(int i=0;i<boostersum;i++){
                    if(boosterqueue[i] == 3){
                        temp = i;
                    }
                }
                for(int i=temp;i<boostersum-1;i++){
                    boosterqueue[i] = boosterqueue[i+1];
                }
                boostersum--;
                if(tasksituation[1] == 1){
                    mission[1]-=1;
                }
            }
    }
}
void boostercheck(){ // check if booster is used
    if(speedboosteropen == 2){
        speedboosteropen = 1;
        speedbooster -= 1;
        for(int i=0;i<boostersum;i++){
            if(boosterqueue[i] == 1){
                temp = i;
            }

        }
        for(int i=temp;i<boostersum-1;i++){
            boosterqueue[i] = boosterqueue[i+1];
        }
        boostersum--;
        if(tasksituation[1] == 1){
            mission[1]-=1;
        }
    }
    if(priceboosteropen == 2){
        priceboosteropen = 1;
        pricebooster -= 1;
        for(int i=0;i<boostersum;i++){
            if(boosterqueue[i] == 2){
                temp = i;
            }

        }
        for(int i=temp;i<boostersum-1;i++){
            boosterqueue[i] = boosterqueue[i+1];
        }
        boostersum--;
        if(tasksituation[1] == 1){
            mission[1]-=1;
        }
    }
}
void areacheck(){ // area check
    int temp;
    printf("Which result of the area you want to check?\n");
    printf("  [1] Area 1\n");
    printf("  [2] Area 2\n");
    printf("  [3] Area 3\n");
    printf("  [4] Area 4\n");
    areaboosteropen?printf("  [5] Area 5\n  [6] Done\n"):printf("  [5] Done\n");
    printf("Enter the number(s): ");
    scanf("%d",&temp);
    if(temp<0 || temp >6){
        printf("Invalid input!!!!\n");
        areacheck();
    }
    switch (areasitutaion[temp-1]){
        case 0:
            printf("You make %d hotdogs here!\n", (180/minutes)*(speedboosteropen?2:1));
            printf("You earn $%d!\n", (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1));
            areacheck();
            break;
        case 1:
            printf("Can't you tell how poor you are?\n");
            printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
            printf("You make %d hotdogs here!\n", (180/minutes)*(speedboosteropen?2:1));
            printf("You earn $%d!\n", (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1));
            areacheck();
            break;
        case 2:
            printf("Do you want to travel through time?\n");
            printf("GO WORK!!\n");
            printf("You make %d hotdogs here!\n", (180/minutes)*(speedboosteropen?2:1));
            printf("You earn $%d!\n", (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1));
            areacheck();
            break;
        case 3:
            printf("You glimpse the secret of wind.\n");
            printf("Your hands can move faster now.\n");
            areacheck();
            break;
        case 4:
            printf("You feel the soul of the ingredients.\n");
            printf("Your hotdogs are more appetizing now.\n");
            areacheck();
            break;
        case 5:
            if(!areaboosteropen){
                break;
            }
            else{
                printf("You make %d hotdogs here!\n", (180/minutes)*(speedboosteropen?2:1));
                printf("You earn $%d!\n", (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1));
            }
            areacheck();
            break;
        case 6:
            if(!areaboosteropen){
                printf("Invalid input!!!!\n");
                areacheck();
                break;
            }
            else{
                break;
            }
        default:
            printf("Invalid input!!!!\n");
            areacheck();
            break;   
    }
}
void end(){ // check if end
    int temp;
    printf("Do you want to continue or exit?\n");
    printf("  [1] Continue\n");
    printf("  [2] Exit\n");
    printf("Enter the number(s): ");
    scanf("%d",&temp);
    switch (temp){
        case 1:
            printf("You get one free choice.\n");
            freechoice += 1;
            break;
        case 2:
            printf("We will miss you. Bye!\n");
            exit(0);
        default:
            printf("Invalid input!!!!\n");
            end();
    }
}
int lotterybuild(){ // lotterybuild
    int refresh;
    refresh = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            if(lottery[i][j] != 0){
                refresh = 0;
            }
        }
    }
    if(refresh == 1){
        lotteryprice = 500;
        n += 2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
                lottery[i][j] = 1;
            }
        }
    }
    lotterynspace = 0;
    for(int i = n*n; i>0;i /= 10){
        lotterynspace ++;
    }
    for (int i = 0; i < n; i++){
        printf("+");
        for (int j = 0; j < n; j++){
            for (int k = 0; k < lotterynspace+2; k++) printf("-");
            printf("+");
        }
        printf("\n|");
        for (int j = 0; j < n; j++){
            if (lottery[i][j] == 0){
                printf(" %*c |",lotterynspace,'x');
            } 
            else{
                printf(" %*d |",lotterynspace, n*i+j+1);
            }
        }
        printf("\n");
    }
    printf("+");
    for (int j = 0; j < n; j++){
        for (int k = 0; k < lotterynspace+2; k++) printf("-");
        printf("+");
    }
    printf("\n");
    printf("You can choose\n");
    freechoice? printf("  [number on cell] to open (- $0)\n"):printf("  [number on cell] to open (- $%d)\n", lotteryprice);
    printf("  [0] to continue the game\n");
    printf("Enter the number(s): ");
    scanf("%d",&temp);
    if(temp == 0){
        return 0; // 改成跳出
    }
    if(temp <= 0 || temp > n*n){
        printf("Invalid input!!!!\n");
        lotterybuild();
    }
    if(lottery[(temp-1)/n][(temp-1)%n] == 0){
        printf("Invalid input!!!!\n");
        lotterybuild();
    }
    if(freechoice == 0 && dollars < lotteryprice){
        printf("You have no money!\n");
        return 0; // 記得改成新的一天
    }
    else if(freechoice > 0){
        freechoice -= 1;
        if(tasksituation[3] == 1){
            mission[3]--;
        }
    }
    else{
        dollars -= lotteryprice;
        lotteryprice +=500;
        if(tasksituation[3] == 1){
            mission[3]--;
        }
    }
    lotterychoose(temp);
}
int lotterychoose(){ // do lottery choose
    lottery[(temp-1)/n][(temp-1)%n] = 0;
    cell = temp;
    lotterynumber = rand()%9+1;
    temp = cell;
    switch(lotterynumber){
        case 1:
            printf("Fortune, fortune! You get $%d!\n", price*100);
            dollars += price*100;
            lotterybuild();
            break;
        case 2:
            printf("You get an extra choice!\n");
            freechoice += 1;
            lotterybuild();
            break;
        case 3:
            if((temp - 1)/n == 0){
                temp2 = n-1;
            }
            else{
                temp2 = (temp-1)/n - 1;
            }
            if(lottery[temp2][(temp-1)%n] == 0){
                printf("Bad Luck :(\n");
            }
            else{
                temp = temp2*n + 1 + (temp-1)%n;
                printf("Another open on %d!\n", temp);
                lotterychoose(temp);
                break;
            }
            lotterybuild();
            break;
        case 4:
            if((temp - 1)/n == n-1){
                temp2 = 0;
            }
            else{
                temp2 = (temp-1)/n + 1;
            }
            if(lottery[temp2][(temp-1)%n] == 0){
                printf("Bad Luck :(\n");
            }
            else{
                temp = temp2*n + 1 + (temp-1)%n;
                printf("Another open on %d!\n", temp);
                lotterychoose(temp);
                break;
            }
            lotterybuild();
            break;
        case 5:
            if((temp - 1)%n == 0){
                temp2 = n-1;
            }
            else{
                temp2 = (temp-1)%n - 1;
            }
            if(lottery[(temp-1)/n][temp2] == 0){
                printf("Bad Luck :(\n");
            }
            else{
                temp = ((temp-1)/n)*n + temp2 + 1;
                printf("Another open on %d!\n", temp);
                lotterychoose(temp);
                break;
            }
            lotterybuild();
            break;
        case 6:
            if((temp - 1)%n == n-1){
                temp2 = 0;
            }
            else{
                temp2 = (temp-1)%n + 1;
            }
            if(lottery[(temp-1)/n][temp2] == 0){
                printf("Bad Luck :(\n");
            }
            else{
                temp = ((temp-1)/n)*n + temp2 + 1;
                printf("Another open on %d!\n", temp);
                lotterychoose(temp);
                break;
            }
            lotterybuild();
            break;
        case 7:
            printf("You get a speedbooster!!\n");
            speedbooster += 1;
            boostersum++;
            boosterjudge();
            lotterybuild();
            break;
        case 8:
            printf("You get a pricebooster!!\n");
            pricebooster += 1;
            boostersum++;
            boosterjudge();
            lotterybuild();
            break;
        case 9:
            printf("You get a areabooster!!\n");
            areabooster +=1;
            boostersum++;
            boosterjudge();
            lotterybuild();
            break;
    }
}
void boosterjudge(){ // booster out of slots judge
    if(boostersum>boosterslots){
        printf("Oops! Your boosters are too musch!\n");
        boostersum--;
        switch(boosterqueue[0]){
            case 1:
                printf("You lose a speedbooster!\n");
                speedbooster--;
                break;
            case 2:
                printf("You lose a pricebooster!\n");
                pricebooster--;
                break;
            case 3:
                printf("You lose a areabooster!\n");
                areabooster--;
                break;
        }
        for(int i=0; i<boosterslots-1;i++){
            boosterqueue[i] = boosterqueue[i+1];
        }
    }

}
int mapsystem(){ // mapsystem
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            switch(mapsituation[i][j]){
                case 0:
                    printf(". ");
                    break;
                case 1:
                    printf("P ");
                    break;
                case 2:
                    printf("M ");
                    break;
                case 3:
                    printf("B ");
                    break;
                case 4:
                    printf("T ");
                    break;
            }
        }
        printf("\n");
    }
    mapmoveinvalid:
    printf("Every step cost $25.\n");
    printf("  [1]up.\n");
    printf("  [2]down.\n");
    printf("  [3]left.\n");
    printf("  [4]right.\n");
    printf("  [5]quit.\n");
    printf("Enter the number(s) if you want to move: ");
    scanf("%d", &temp);
    if(temp == 1 || temp == 2 || temp == 3 || temp == 4){
        if(tasksituation[4] == 1){
            mission[4]--;
        }
        if(dollars<25){
            printf("You have no money!\n");
            return 0;
        }
    }
    switch (temp){
        case 1:
            if(playerlocation/8==0){
                printf("Oops!you are gonna bump into the edge!please select your action again!\n");
                goto mapmoveinvalid;
            }
            mapsituation[playerlocation/8][playerlocation%8] = 0;
            playerlocation-=8;
            eventcheck();
            // mapsituation[playerlocation/8][playerlocation%8] = 1;
            dollars-=25;
            mapsystem();
            break;
        case 2:
            if(playerlocation/8==7){
                printf("Oops!you are gonna bump into the edge!please select your action again!\n");
                goto mapmoveinvalid;
            }
            mapsituation[playerlocation/8][playerlocation%8] = 0;
            playerlocation+=8;
            eventcheck();
            dollars-=25;
            mapsystem();
            break;
        case 3:
            if(playerlocation%8==0){
                printf("Oops!you are gonna bump into the edge!please select your action again!\n");
                goto mapmoveinvalid;
            }
            mapsituation[playerlocation/8][playerlocation%8] = 0;
            playerlocation--;
            eventcheck();
            dollars-=25;
            mapsystem();
            break;
        case 4:
            if(playerlocation%8==7){
                printf("Oops!you are gonna bump into the edge!please select your action again!\n");
                goto mapmoveinvalid;
            }
            mapsituation[playerlocation/8][playerlocation%8] = 0;
            playerlocation++;
            eventcheck();
            dollars-=25;
            mapsystem();
            break;
        case 5:
            break;
        default:
            printf("Invalid input!\n");
            goto mapmoveinvalid;
    }
}
void mapjudge(){  // judge if there are no money bags and booster on the map
    int temp = 0;
    for(int i=0;i<8;i++){
        for(int j = 0; j < 8 ; j++){
            if(mapsituation[i][j] == 2){
                temp = 1;
                break;
            }
        }
        if(temp == 1){
            break;
        }
    }
    if(temp == 0){
        while(1){
            temp = rand()%64;
            if(mapsituation[temp/8][temp%8]==0){
                printf("New money bags appear!\n");
                mapsituation[temp/8][temp%8] = 2;
                break;
            }
        }
    }
    temp = 0;
    for(int i=0;i<8;i++){
        for(int j = 0; j < 8 ; j++){
            if(mapsituation[i][j] == 3){
                temp = 1;
                break;
            }
        }
        if(temp == 1){
            break;
        }
    }
    if(temp == 0){
        while(1){
            temp = rand()%64;
            if(mapsituation[temp/8][temp%8]==0){
                printf("New booster appear!\n");
                mapsituation[temp/8][temp%8] = 3;
                break;
            }
        }
    }
}
void eventcheck(){ // check if player step on the event block
    int temp;
    switch(mapsituation[playerlocation/8][playerlocation%8]){  // 2 == M(Money) 3 == B(Booster) 4 == T(Task)
        case 2:
            temp = (playerlocation/8)*(playerlocation%8)*10;
            printf("You got a money bag!\n");
            dollars += temp;
            printf("You earn $%d!Now you have $%d dollars now.\n",temp,dollars);
            break;
        case 3:
            temp = rand()%3+1;
            switch (temp){
                case 1:
                    speedbooster++;
                    boostersum++;
                    printf("You got a speedbooster!\n");
                    printf("Now you have %d speedboosters now.\n",speedbooster);
                    boosterjudge();
                    break;
                case 2:
                    pricebooster++;
                    boostersum++;
                    printf("You got a pricebooster!\n");
                    printf("Now you have %d priceboosters now.\n",pricebooster);
                    boosterjudge();
                    break;
                case 3:
                    areabooster++;
                    boostersum++;
                    printf("You got a areabooster!\n");
                    printf("Now you have %d areaboosters now.\n",areabooster);
                    boosterjudge();
                    break;
            }
            break;
        case 4:
            printf("You got a mission now!\n");
            temp = 0;
            while(1){
                temp = rand()%5;
                if(tasksituation[temp] != 2){
                    break;
                }
            }
            tasksituation[temp] = 1;
            switch(temp+1){
                case 1:
                    printf("mission: sells 50 hotdogs.\n");
                    printf("difficulty:*\n");
                    printf("reward:$500 dollars\n");
                    break;
                case 2:
                    printf("mission: open any of the boosters three times.\n");
                    printf("difficulty:****\n");
                    printf("reward:speedbooster*1 pricebooster*1 areabooster*1\n");
                    break;
                case 3:
                    printf("mission: max your cooking speed.\n");
                    printf("difficulty:*****\n");
                    printf("reward:$50000\n");
                    break;
                case 4:
                    printf("mission: open the lottery 10 times.\n");
                    printf("difficulty:***\n");
                    printf("reward:3 extra choice\n");
                    break;
                case 5:
                    printf("mission: move twenty times on the map.\n");
                    printf("difficulty:**\n");
                    printf("reward:2 more money bags and booster appear the map\n");
                    break;
            }
            printf("You can check your mission before taking your actions in the area.\n");
            break;
    }
    mapsituation[playerlocation/8][playerlocation%8] = 1;
}
int missioncheck(){ //check player's mission situation
    int temp;
    printf("Do you want to check your mission?\n");
    printf("  [1]Yes\n");
    printf("  [2]NO\n");
    printf("Enter the number(s): ");
    scanf("%d",&temp);
    if(temp == 2){
        return 0;
    }
    temp = 5;
    for(int i=0; i<5;i++){
        if(tasksituation[i] == 0){
            temp = 6;
        }
        else if(tasksituation[i] == 1){
            temp = i;
            break;
        }
    }
    if(temp == 5){
        printf("Good job!You finish all the mission!\n");
        return 0;
    }
    else if(temp == 6){
        printf("You have no mission now!\n");
    }
    else{
        printf("You haven't finish your mission yet!\n");
        printf("Keep going!\n");
        printf("Your ");
        switch(temp+1){
                case 1:
                    printf("mission: sells 50 hotdogs.\n");
                    printf("difficulty:*\n");
                    printf("reward:$500 dollars\n");
                    printf("%d/50 left.",mission[0]);
                    break;
                case 2:
                    printf("mission: open any of the boosters 3 times.\n");
                    printf("difficulty:****\n");
                    printf("reward:speedbooster*1 pricebooster*1 areabooster*1\n");
                    printf("%d/3 left.",mission[1]);
                    break;
                case 3:
                    printf("mission: max your cooking speed.\n");
                    printf("difficulty:*****\n");
                    printf("reward:$50000\n");
                    printf("You still need to improve %d times.\n",minutes-1);
                    break;
                case 4:
                    printf("mission: open the lottery 10 times.\n");
                    printf("difficulty:***\n");
                    printf("reward:3 extra choice\n");
                    printf("%d/10 left.",mission[3]);
                    break;
                case 5:
                    printf("mission: move 20 times on the map.\n");
                    printf("difficulty:**\n");
                    printf("reward:2 more money bags and booster appear the map\n");
                    printf("%d/20 left.",mission[4]);
                    break;
            }
    }
}
int missioncomplete(){ // check if mission is complete
    int temp = 0;
    for(int i=0; i<5;i++){
        if(tasksituation[i] == 1){
            temp = i;
            break;
        }
    }
    if(mission[temp] <= 0){
        printf("Well done!You complete the mission!\n");
        switch(temp+1){
            case 1:
                printf("You earn $500 dollars!\n");
                dollars+=500;
                tasksituation[temp] = 2;
                break;
            case 2:
                printf("You get the boosters!\n");
                speedbooster++;
                pricebooster++;
                areabooster++;
                tasksituation[temp] = 2;
                break;
            case 3:
                printf("You earn $50000 dollars!\n");
                dollars+=50000;
                tasksituation[temp] = 2;
                break;
            case 4:
                printf("You get 3 extra choice!\n");
                freechoice++;
                tasksituation[temp] = 2;
                break;
            case 5:
                printf("2 more money bags and boosters appear now!\n");
                for(int i=0; i<2;i++){
                    while(1){
                        temp = rand()%64;
                        if(mapsituation[temp/8][temp%8]==0){
                            mapsituation[temp/8][temp%8] = 2;
                            break;
                        }
                    }
                }
                for(int i=0; i<2;i++){
                    while(1){
                        temp = rand()%64;
                        if(mapsituation[temp/8][temp%8]==0){
                            mapsituation[temp/8][temp%8] = 3;
                            break;
                        }
                    }
                }
                tasksituation[temp] = 2;
                break;
        }
        printf("New mission now appear on the map!\n");
        while(1){
            temp = rand()%64;
            if(mapsituation[temp/8][temp%8]==0){
                mapsituation[temp/8][temp%8] = 4;
                break;
            }
        }
    }
}
//----------------------------------------------------------------
int  main(){
    srand(time(NULL));
    int temp,temp2; // orgin
    for(int i = 0;i < n; i++){ //陣列初始化
        for(int j = 0;j < n; j++){
            lottery[i][j] = 1;
        }
    }
    mission[0] = 50,mission[1] = 3,mission[2] = 1,mission[3] = 10,mission[4] = 20;
    mapinitialization();
    boosterslots = rand()%11+5;
    printf("Welcome, young boss!\n");
    while(1){
        dollarsum = 0;
        begin();
        boosterchoose(&speedboosteropen,&priceboosteropen,&areaboosteropen);
        if(speedbooster == 0){
            speedboosteropen = 0;
        } 
        if(pricebooster == 0){
            priceboosteropen = 0;
        }
        if(areabooster == 0){
            areaboosteropen = 0;
        }
        missioncheck();
        actions(isc,ipc);
        for(int i=0;i<4;i++){
            actionsdo(i);
        }
        boostercheck();
        areasitutaion[4] = 5;
        areasitutaion[5] = 6;
        printf("Well done, you earn $%d today.\n",dollarsum);
        areacheck();
        mapjudge();
        mapsystem();
        missioncomplete();
        end();
        lotterybuild();        
    }

}