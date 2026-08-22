#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n;
    cin>>n;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=(i-1)*n+j;
        }
    }
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int cur=(i-1)*n+j,tot=cur;
            if(j+1<=n)  tot+=(cur+1);
            if(j-1>=1) tot+=(cur-1);
            if(i+1<=n) tot+=(cur+n);
            if(i-1>=1) tot+=(cur-n);

            if(tot>cnt){
                ans=cur,cnt=tot;
            }
        }
    }
    cout<<cnt<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}