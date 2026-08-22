#include <bits/stdc++.h>
using namespace std;
/*

    用dp
    不难想到每个点总是被比它的最短路少1的点更新
    bfs就可以

*/
const int mod=100003;
void sol() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> e(n+1);
    vector<int> dis(n+1,-1),dp(n+1,0);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(u==v){

        }else{
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }
    queue<int> q;
    q.push(1);
    dp[1]=1,dis[1]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int v:e[u]){
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
            if(dis[v]==dis[u]+1){
                dp[v]=(dp[v]+dp[u])%mod;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dis[i]<<" ";
    // }
    // cout<<'\n';
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}