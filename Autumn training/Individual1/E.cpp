#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int mod=998244353;
void sol(){
    int n;
    cin>>n;
    vector<vector<int>> e(n+1);
    vector<int> dp1(n+1,0),dp2(n+1,0);
    // vector<int> fa(n+1);
    for(int i=2;i<=n;i++){
        int f;
        cin>>f;
        // fa[i]=f;
        e[f].push_back(i);
    }
    dp1[1]=1,dp2[1]=1;
    queue<pair<int,int>> que;
    que.push({1,1});
    int ans=1;
    while(que.size()){
        auto[u,level]=que.front();
        que.pop();
        for(int v:e[u]){
            que.push({v,level+1});
            if(level==1){
                dp1[v]=1,dp2[level+1]=(dp2[level+1]+1)%mod;
                ans=(ans+dp1[v])%mod;
            }else{
                dp1[v]=(dp2[level]-dp1[u]+mod)%mod;
                dp2[level+1]=(dp2[level+1]+dp1[v])%mod;
                ans=(ans+dp1[v])%mod;
            }
        }
    }   
    // for(int  i=1;i<=n;i++){
    //     cout<<i<<" "<<dp1[i]<<'\n';
    // }
    // cout<<'\n';
    cout<<ans<<'\n';
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