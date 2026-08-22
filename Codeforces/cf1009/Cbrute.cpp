#include <bits/stdc++.h>
using namespace std;
#define int long long  

void sol(){
    int x,y;
    cin>>x;
    for(int i=1;i<x;i++){
        int mid=x^y;
        if(x+y>mid&&x+mid>y&&y+mid>x){
            cout<<y<<'\n';
            return ;
        }
    }
    cout<<"-1\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0ll;
}