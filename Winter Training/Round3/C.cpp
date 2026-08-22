#include <bits/stdc++.h>
using namespace std;
/*

    考虑dp，有两种构成方法，第一种是还可以继续向上延伸的毛毛虫，那么只需要一个子树
    还有一种是由自己的两个子树构成的毛毛虫

*/


vector<vector<int>> e,dp;
vector<int> deg;
void dfs(int u,int fa){
    if(u!=1){
        deg[u]--;
    }
    if(!deg[u]){
        dp[u][1]=dp[u][2]=1;
        return ;
    }
    int fmx=-1,smx=-1;
    for(int v:e[u]){
        if(fa^v){
            dfs(v,u);
            if(dp[v][1]>fmx){
                smx=max(fmx,smx);
                fmx=dp[v][1];
            }else if(dp[v][1]>smx){
                smx=dp[v][1];
            }
        }
    }
    dp[u][1]+=max(0,fmx+deg[u]);
    dp[u][2]+=max(0,fmx+max(0,smx)+deg[u]);
    if(u==1){
        dp[u][2]--;
    }
    // cout<<u<<" "<<dp[u][1]<<" "<<fmx<<'\n';
}

void sol() {
    int n,m;
    cin>>n>>m;
    e.resize(n+1);
    dp.resize(n+1,vector<int>(3,0));
    deg.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
        deg[a]++,deg[b]++;
    }
    
    dfs(1,0);
    int ans=-1;
    for(int i=1;i<=n;i++){
        // cout<<i<<" ";
        // cout<<deg[i]<<" "<<dp[i][1]<<" "<<dp[i][2]<<'\n';
        ans=max({ans,dp[i][1],dp[i][2]});
    }
    cout<<ans;
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