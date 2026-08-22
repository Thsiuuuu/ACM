#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    double allScore=0,allPerform=0;

    double curScore=0,curPerform=0;
    while(cin>>curScore>>curPerform){
        if(curScore==0&&curPerform==0){
            break;
        }

        double tempPerform=curPerform-50;
        tempPerform/=10;
        allPerform+=(tempPerform*curScore);
        allScore+=curScore;
    }
    cout<<"总学分: "<<allScore<<"\n"<<"总绩点: "<<allPerform/allScore;
    return 0;
}