#include <stdio.h>

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


int  main(){
    int dollars = 100,minutes = 15,price = 30,isc = 50,ipc = 100,dollarsum = 0,temp,temp2; // orgin
    int speedbooster = 0,pricebooster = 0,areabooster = 0; // boost count
    int speedboosteropen = 0,priceboosteropen = 0,areaboosteropen = 0; // boost open close
    int area[5] = {0}; //check area
    int areasitutaion[6];
    int n=3,lottery[100][100],freechoice = 0,lotteryprice = 500,lotterynspace = 0;
    int lotterynumber,cell;
    int refresh = 0;
    for(int i = 0;i < n; i++){
        for(int j = 0;j < n; j++){
            lottery[i][j] = 1;
        }
    }
    printf("Welcome, young boss!\n");
    while(1){
        dollarsum = 0;
        printf("Chop chop, It's dawn.\n");
        printf("You have %d dollars.\n",dollars);
        printf("You need %d minutes to make a hotdog.\n",minutes);
        printf("The price of a hotdog is $%d.\n",price);
        printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n",speedbooster,pricebooster,areabooster);
        while(1){ //booster choose
            boostchooseagain:
            printf("Open/Close boosters:\n");
            speedboosteropen?printf("  [1] Speed booster (now open)\n"):printf("  [1] Speed booster (now close)\n");
            priceboosteropen?printf("  [2] Price booster (now open)\n"):printf("  [2] Price booster (now close)\n");
            areaboosteropen?printf("  [3] Area  booster (now open)\n"):printf("  [3] Area  booster (now close)\n");
            printf("  [4] Finish\n");
            printf("Enter the number(s): ");
            temp = booster(&speedboosteropen,&priceboosteropen,&areaboosteropen);
            if(temp == 0){
                break;
            }
            else if(temp == 2){
                printf("Invalid input!!!!\n");
                goto boostchooseagain;
            }
            else{
                continue;
            }
        }
        if(speedbooster == 0){
            speedboosteropen = 0;
        } 
        if(pricebooster == 0){
            priceboosteropen = 0;
        }
        if(areabooster == 0){
            areaboosteropen = 0;
        }
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
                areachooseagain:
                printf("Invalid input!!!!\n");
                printf("Actions you can take at Area %d:\n", i+1);
                printf("  [1] Sell the hotdogs\n");
                printf("  [2] Improve your cooking speed\n");
                printf("  [3] Improve your hotdog flavor\n");
                printf("Enter the number(s): ");
                scanf("%d",&area[i]);
                if(area[i] != 1 && area[i] != 2 && area[i] != 3){
                    goto areachooseagain;
                }
            }
        }
        for(int i=0;i<4;i++){
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
                    break;
                case 2:
                    if(dollars<isc){
                        areasitutaion[i] = 1;
                        goto sellhotdog;
                    }
                    else{
                        if(minutes==1){
                            areasitutaion[i] = 2;
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
                    }
            }
        }
        if(speedboosteropen == 2){
            speedboosteropen = 1;
            speedbooster -= 1;
        }
        if(priceboosteropen == 2){
            priceboosteropen = 1;
            pricebooster -= 1;
        }
        areasitutaion[4] = 5;
        areasitutaion[5] = 6;
        printf("Well done, you earn $%d today.\n",dollarsum);
        areacheckagain:
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
            goto areacheckagain;
        }
        switch (areasitutaion[temp-1]){
            case 0:
                printf("You make %d hotdogs here!\n", (180/minutes)*(speedboosteropen?2:1));
                printf("You earn $%d!\n", (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1));
                goto areacheckagain;
            case 1:
                printf("Can't you tell how poor you are?\n");
                printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                printf("You make %d hotdogs here!\n", (180/minutes)*(speedboosteropen?2:1));
                printf("You earn $%d!\n", (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1));
                goto areacheckagain;
            case 2:
                printf("Do you want to travel through time?\n");
                printf("GO WORK!!\n");
                printf("You make %d hotdogs here!\n", (180/minutes)*(speedboosteropen?2:1));
                printf("You earn $%d!\n", (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1));
                goto areacheckagain;
            case 3:
                printf("You glimpse the secret of wind.\n");
                printf("Your hands can move faster now.\n");
                goto areacheckagain;
            case 4:
                printf("You feel the soul of the ingredients.\n");
                printf("Your hotdogs are more appetizing now.\n");
                goto areacheckagain;
            case 5:
                if(!areaboosteropen){
                    goto end;
                }
                else{
                    printf("You make %d hotdogs here!\n", (180/minutes)*(speedboosteropen?2:1));
                    printf("You earn $%d!\n", (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1));
                }
                goto areacheckagain;
            case 6:
                if(!areaboosteropen){
                    printf("Invalid input!!!!\n");
                    goto areacheckagain;
                }
                else{
                    goto end;
                }
            default:
                printf("Invalid input!!!!\n");
                goto areacheckagain;    
        }
        end:
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
                return 0;
            default:
                printf("Invalid input!!!!\n");
                goto end;
        }
        lotteryagain:
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
            continue; // 改成跳出
        }
        if(temp <= 0 || temp > n*n){
            printf("Invalid input!!!!\n");
            goto lotteryagain;
        }
        if(lottery[(temp-1)/n][(temp-1)%n] == 0){
            printf("Invalid input!!!!\n");
            goto lotteryagain;
        }
        if(freechoice == 0 && dollars < lotteryprice){
            printf("You have no money!\n");
            continue; // 記得改成新的一天
        }
        else if(freechoice > 0){
            freechoice -= 1;
        }
        else{
            dollars -= lotteryprice;
            lotteryprice +=500;
        }
        extrachoice:
        lottery[(temp-1)/n][(temp-1)%n] = 0;
        cell = temp;
        lotterynumber = 0;
        while(temp != 0){
            lotterynumber = lotterynumber*10 + temp%10;
            temp /= 10;
        }
        temp = lotterynumber;
        lotterynumber = 0;
        for(int i = 0;temp != 0;i++){
            temp2 = temp%10;
            for(int j = 0;j < i;j++){
                temp2 *= 16;
            }
            temp /=10 ;
            lotterynumber += temp2;
        }
        lotterynumber %= 9;
        lotterynumber += 1;
        temp = cell;
        switch(lotterynumber){
            case 1:
                printf("Fortune, fortune! You get $%d!\n", price*100);
                dollars += price*100;
                goto lotteryagain;
            case 2:
                printf("You get an extra choice!\n");
                freechoice += 1;
                goto lotteryagain;
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
                    goto extrachoice;
                }
                goto lotteryagain;
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
                    goto extrachoice;
                }
                goto lotteryagain;
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
                    goto extrachoice;
                }
                goto lotteryagain;
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
                    goto extrachoice;
                }
                goto lotteryagain;
            case 7:
                printf("You get a booster!!\n");
                speedbooster += 1;
                goto lotteryagain;
            case 8:
                printf("You get a booster!!\n");
                pricebooster += 1;
                goto lotteryagain;
            case 9:
                printf("You get a booster!!\n");
                areabooster +=1;
                goto lotteryagain;
        }

        
    }



}