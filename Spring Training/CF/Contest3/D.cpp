#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long


const int N=2e5+10;
vector<int> e[N];
vector<ll> g(N,0),f(N,0),siz(N,0);
int n;

void dfs1(int u,int fa){
    siz[u]=1;
    for(int v:e[u]){
        if(v^fa){
            dfs1(v,u);
            f[u]+=f[v]+siz[v]*(siz[v]-1)/2;
            siz[u]+=siz[v];
        }
    }
}

void dfs2(int u,int fa){
    if(u!=1){
        g[u]=g[fa]+(n-siz[u])*(n-siz[u]-1)/2+f[fa]-f[u]-siz[u]*(siz[u]-1)/2;
    }
    for(int v:e[u]){
        if(v^fa){
            dfs2(v,u);   
        }
    }
}   


void sol() {
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        // cout<<g[i]<<'\n';
        cout<<f[i]+g[i]<<'\n';
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