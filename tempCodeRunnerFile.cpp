#include <bits/stdc++.h>

using namespace std;
struct Student{
    string name;
    int score;
};
int main(){
    int n,sc,itemp;
    string na,stemp;
    cout << "how many students?"<< endl;
    cin >> n;
    Student *p = new Student[n];
    for(int i=0; i<n;i++){
        cout << "Student name:"<<endl;
        cin >> p[i].name;
        cout << "Student score:"<<endl;
        cin >> p[i].score;
    }
    for(int i=n-1; i>0; i--){
        for(int j=0; j<=i-1; j++){
            if(p[j].score < p[j+1].score){
                itemp = p[j].score;
                stemp = p[j].name;
                p[j].score = p[j+1].score;
                p[j].name = p[j+1].name;
                p[j+1].score = itemp;
                p[j+1].name = stemp;
            }
        }
    }
    for(int i = 0;i<n;i++){
        std::cout <<"student: "<< p[i].name <<" score: "<<p[i].score << std::endl;
    }
}