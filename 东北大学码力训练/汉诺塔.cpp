#include <iostream>
#include <algorithm>

using namespace std;


void f(int i,int num1,int num2,int num3){
    if(i==1) cout<<num1<<" "<<num2<<"\n";
    else{
        f(i-1,num1,num3,num2);
        cout<<num1<<" "<<num2<<"\n";
        f(i-1,num3,num2,num1);
    }
}

void hanoi(int n){
    if(n>0){
        f(n,1,3,2);
    }
}

int main(){
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<"\n";
    hanoi(n);
}