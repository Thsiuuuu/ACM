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
int n,m;
const int N=3e5+10;
ll c[N],f[N],pre[N],A[N],B[N];
int dep[N],st[N][20];
VI e[N];
void dfs1(int u,int fa){
    dep[u]=dep[fa]+1,st[u][0]=fa;
    for(int i=1;i<20;i++) st[u][i]=st[st[u][i-1]][i-1];
    for(int v:e[u]){
        if(v==fa) continue;
        dfs1(v,u);
    } 
}
void dfs2(int u,int fa){
    A[u]=B[u]=1e18;
    f[u]=c[u];
    for(int v:e[u]){
        if(v==fa) continue;
        dfs2(v,u);
        if(f[v]<=A[u]) B[u]=A[u],A[u]=f[v];
        else if(f[v]<=B[u]) B[u]=f[v];
    }
    f[u]=min(f[u],A[u]+B[u]);
}
void dfs3(int u,int fa){
    if(u!=1) pre[u]=pre[fa]+((f[u]==A[fa])?B[fa]:A[fa]);
    for(int v:e[u]){
        if(v==fa) continue;
        dfs3(v,u);
    }
}
int LCA(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=19;i>=0;i--){
        if(dep[st[x][i]]>=dep[y]) x=st[x][i];
    }
    if(x==y) return y;
    for(int i=19;i>=0;i--){
        if(st[x][i]!=st[y][i]) x=st[x][i],y=st[y][i];
    }
    return st[x][0];
}
void sol() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    dfs3(1,0);
    while(m--){
        int x,y;cin>>x>>y;
        int lca=LCA(x,y);
        if(lca!=y){
            cout<<"-1\n";
            continue;
        }
        cout<<pre[x]-pre[y]<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}