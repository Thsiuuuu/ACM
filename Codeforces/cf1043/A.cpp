#include <bits/stdc++.h>
using namespace std;
void sol(){
    string a,b,c;
    int n,m;
    cin>>n;
    cin>>a;
    cin>>m;
    cin>>b>>c;
    for(int i=0;i<m;i++){
        if(c[i]=='V') a=b[i]+a;
        else a=a+b[i];
    }
    cout<<a<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}