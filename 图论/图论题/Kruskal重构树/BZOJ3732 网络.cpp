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
struct Edge{
    int u,v;
    ll w;
    bool operator<(const Edge&other)const{
        return w<other.w;
    }
};
const int N=15010;
vector<Edge> ew;
VI e[N<<1];
int n,m,k;
int cnt,fa[N<<1],st[N<<1][20],dep[N<<1],w[N<<1];
int find(int x){
    return  x==fa[x]?x:fa[x]=find(fa[x]);
}
void dfs(int u,int p){
    dep[u]=dep[p]+1;
    st[u][0]=p;
    for(int i=1;i<=19;i++){
        st[u][i]=st[st[u][i-1]][i-1];
    }
    for(int v:e[u]){
        dfs(v,u);
    }
}
int lca(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=19;i>=0;i--){
        if(dep[st[a][i]]>=dep[b]) a=st[a][i];
    }
    if(a==b) return a;
    for(int i=19;i>=0;i--){
        if(st[a][i]!=st[b][i]) a=st[a][i],b=st[b][i];
    }
    return st[a][0];
}
void sol() {
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;ll wi;cin>>u>>v>>wi;
        ew.push_back({u,v,wi});
    }
    sort(ew.begin(),ew.end());
    cnt=n;
    int tot=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(auto [u,v,wi]:ew){
        u=find(u),v=find(v);
        if(u^v){
            ++tot,++cnt;
            fa[u]=fa[v]=fa[cnt]=cnt;
            e[cnt].push_back(u);
            e[cnt].push_back(v);
            w[cnt]=wi;
        }
        if(tot==n-1) break;
    }
    dep[cnt]=1;
    dfs(cnt,0);
    while(k--){
        int u,v;cin>>u>>v;
        cout<<w[lca(u,v)]<<'\n';
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