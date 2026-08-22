#include <bits/stdc++.h>
using namespace std;

void check1(long long n){
    for(int i=64;i>=0;i--){
        if((n>>i)&1){
            cout<<i<<" ";
        }
    }
    cout<<'\n';
}
void check2(unsigned long long n){
    for(int i=64;i>=0;i--){
        if((n>>i)&1){
            cout<<i<<" ";
        }
    }
    cout<<'\n';
}

void sol(){

    int n;
    cin>>n;
    cout<<n<<"!\n";
    check1(n);
    check2(n);
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}