#include <bits/stdc++.h>
using namespace std;

const int mod=2017;
/*

    进行for each循环的时候不要插入元素，否则有可能会RE
    这个dp需要确定每一个点的状态，并且要把自不自爆划分开来，同时对时间有依赖
    所以说是一个三维的dp，但是时间可以采用滚动数组进行优化
    用前一个时间的状态去更新后面时间的状态

*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m,t;
    cin>>n>>m;
    vector<vector<int>> e(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin>>t;
    vector<vector<vector<int>>> dp(2,vector<vector<int>>(n+1,vector<int>(2,0)));
    dp[0][1][0]=dp[0][1][1]=1;
    vector<int> has,st(n+1);
    st[1]=1;
    has.push_back(1);
    int sum=0;
    for(int i=0;i<t;i++){
        for(int j=0,u;j<has.size();j++){
            u=has[j];
            for(int v:e[u]){
                if(st[v]==0){
                    st[v]=1;
                    has.push_back(v);
                }
                dp[(i+1)%2][v][1]=(dp[(i+1)%2][v][1]+dp[i%2][u][1])%mod;
            }
            dp[(i+1)%2][u][1]=(dp[(i+1)%2][u][1]+dp[i%2][u][1])%mod;
            dp[(i+1)%2][u][0]=(dp[(i+1)%2][u][0]+dp[i%2][u][1])%mod;
            sum=(sum+dp[(i+1)%2][u][0])%mod;
            dp[i%2][u][1]=dp[i%2][u][0]=0;
        }
    }
    // for(int i=0;i<=t;i++){
    //     for(int u:has){
    //         cout<<i<<" "<<u<<" "<<dp[i][u][0]<<" "<<dp[i][u][1]<<'\n';
    //     }
    // }
    for(int u:has){
        sum=(sum+dp[t%2][u][1])%mod;
    }
    cout<<sum;
    return 0;
}