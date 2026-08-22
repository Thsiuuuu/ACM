#include <bits/stdc++.h>
using namespace std;
// #define int long long 
#define ll long  long 
const ll mod=998244353;
struct node{
    int lst;
    int nw;
};
void sol(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> e(n+1);
    vector<ll> wgt(n+1);
    for(int i=1;i<=n;i++){
        cin>>wgt[i];
    }
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        e[u].push_back(v);
    }
    queue<node> que;
    ll ans=0;
    for(int u=1;u<=n;u++){
        for(int v:e[u]){
            que.push({u,v});
            ans=(ans+1ll)%mod;
        }
    }
    while(que.size()){
        auto [lst,nw]=que.front();
        que.pop();
        // cout<<lst<<" "<<nw<<'\n';
        for(int v:e[nw]){
            if(wgt[v]==wgt[nw]+wgt[lst]){
                // cout<<wgt[v]<<" "<<wgt[nw]<<" "<<wgt[lst]<<'\n';
                que.push({nw,v});
                ans=(ans+1ll)%mod;
            }
        }
    }
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