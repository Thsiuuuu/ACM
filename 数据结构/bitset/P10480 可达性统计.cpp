#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
/*
多测清空，long long ，是否对需要修改的变量赋值了
想不出来注意换思路
注意数据范围，枚举答案是否可行
*/
bitset<30002> f[30002];
VI e[30002];
bool vis[30002];
int n,m;
void dfs(int u){
    vis[u]=true;
    for(int v:e[u]){
        if(!vis[v]) dfs(v);
        f[u]|=f[v];
    }
}
void sol() {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        f[x][y]=1;
        e[x].push_back(y);
    }
    for(int i=1;i<=n;i++) f[i][i]=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
        cout<<f[i].count()<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}