#include <bits/stdc++.h>
using namespace std;
/*

    树形的可行性dp
    因为需要解决当前节点是否可以通过摇3的倍数的点进行解决，可以尝试是否可以通过解决子树的问题，来解决这个问题
    所以需要设计两维，第一维表示节点，第二维表示%3的余数
    那么就相当于用子树是否可行，合起来去更新当前的节点是否可行，这里有两种更新方法
    第一种是遍历一个子树就合并一次，时间复杂度最差不超过9n
    第二种是选取每个儿子可行的最小余数，然后采用调整法，去记录每个节点可以调整多少，要么+1，要么+2,进行动态的调整

*/
void sol() {
    int n;
    cin>>n;
    vector<vector<int>> e(n+1);
    vector<array<int,3>> dp(n+1,{0,0,0});
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    auto dfs=[&](auto&&self,int u,int fa){
        if(u!=1&&e[u].size()==1){
            dp[u][1]=1;
            return ;
        }
        dp[u][0]=1;
        for(int v:e[u]){
            if(v^fa){
                self(self,v,u);
                array<int,3> nwone={0,0,0};
                for(int i=0;i<=2;i++){
                    for(int j=0;j<=2;j++){
                        nwone[(i+j)%3]|=(dp[u][i]&&dp[v][j]);
                    }
                }
                dp[u]=nwone;
            }
        }
        dp[u][1]=1;
    };

    dfs(dfs,1,0);
    cout<<(dp[1][0]?"YES":"NO")<<'\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}