#include <bits/stdc++.h>
using namespace std;
#define int long long  

const int mod=998244353;
/*
    如果采用爆搜的方法，必然会超时
    可以考虑一个反向菊花图再接上一个菊花图，这样可以到达(m/2)^2的数量级
    观察到任意两个点必然是一个答案
    如果这两个点进行延伸，不妨设u->v->w，
    可以考虑每一个边的贡献，自己本身就是一次，还可以从v->w进行继承
    需要满足被继承的边必须有u->w且cost[w]=cost[u]+cost[v]
    如果暴力去遍历的话，上面的反正菊花图仍然可以卡到(m^2)的数量级
    因为这里需要的是存在一个点w,满足u->w且cost[w]=cost[u]+cost[v]
    所以可以设状态dp[][cost[]]，第一维表示源点，第二维表示它的边的终点的点权
    就可以列出来点之间的转移方程dp[u][cost[v]]=(1+dp[v][cost[u]+cost[v]])
    我们需要快速找到v的邻接点里面存不存在cost[u]+cost[v]点权的点w，并且还需要这个值
    所以用map存，单次最多O(logm)
    这个转移总是要用到大的边权，所以要从大到小排序，进行转移
    总的时间复杂度O(mlogm)

    这里最开始出现了错误，是因为一个点有可能有多个相邻点权的点，每次访问都会置为1
    所以代码实现上是对每条边的初始贡献就+1了
    准确来说，这个dp值其实表示的是以u为起点，到它的相邻点权为cost[v]的点的所有可能的可能数
*/

struct Edge{
    int u,v;
    int val;
    bool operator<(const Edge&others)const{
        return val>others.val;
    }
};
void sol(){
    int n,m;
    cin>>n>>m;
    vector<Edge> e(m);
    vector<int> cost(n+1);
    vector<map<int,int>> mp(n+1);
    for(int i=1;i<=n;i++) cin>>cost[i];
    for(int i=0;i<m;i++){
        cin>>e[i].u>>e[i].v;
        e[i].val=cost[e[i].v];
        mp[e[i].u][e[i].val]+=1;
    }
    sort(e.begin(),e.end());
    int ans=0ll;
    for(auto [u,v,val]:e){
        // mp[u][val]=1ll;//一个点有多个相同点权的点的话，会覆盖之前的权值
        auto it=mp[v].find(cost[u]+cost[v]);
        if(it!=mp[v].end()){
            mp[u][val]=(mp[u][val]+it->second)%mod;
        }
    }
    for(int u=1;u<=n;u++){
        for(const auto&[val,num]:mp[u]){
            ans=(ans+num)%mod;
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