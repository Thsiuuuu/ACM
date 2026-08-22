#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
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
ll g[101][101][26];
vector<pii> e[101];
int dfs(int u,int v,int w){
    if(g[u][v][w]) return g[u][v][w];
    for(const auto&[ne,nw]:e[v]){
        if(nw<w) continue;
        if(dfs(ne,u,nw)==-1) return g[u][v][w]=1;
    }
    return g[u][v][w]=-1;
}
void sol() {
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;char c;cin>>u>>v>>c;
        e[u].push_back({v,c-'a'});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int w=0;w<26;w++){
                g[i][j][w]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<((dfs(j,i,0)==1)?"A":"B");
        }
        cout<<'\n';
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