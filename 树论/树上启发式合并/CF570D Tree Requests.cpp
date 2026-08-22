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
const int N=500010;
vector<int> e[N];
int c[N],siz[N],son[N];
int cnt[N],ans[N],dep[N];
char zi[N];
struct Query{
    int u,h;  
    bool is=false;
    int idx;
    Query(){}
    Query(int u,int h,int idx):u(u),h(h),idx(idx){}
}Q[N];
struct Info{
    vector<Query> vc;
    Info(){}
};
vector<Info> a;
void add(int u,int fa,int val,int ban,int depth){
    dep[depth]^=(1<<(zi[u]-'a'));
    for(int v:e[u]){
        if(v==fa||v==ban) continue;
        add(v,u,val,ban,depth+1);
    }
}
void dfs1(int u,int fa){
    siz[u]=1,son[u]=0;
    for(int v:e[u]){
        if(fa^v){
            dfs1(v,u);
            siz[u]+=siz[v];
            if(siz[v]>siz[son[u]]) son[u]=v;
        }
    }
}
void dfs2(int u,int fa,bool keep,int depth){
    for(int v:e[u]){
        if(v==fa||v==son[u]) continue;
        dfs2(v,u,false,depth+1);
    }
    if(son[u]){
        dfs2(son[u],u,true,depth+1);
    }
    add(u,fa,1,son[u],depth);
    for(auto&[v,h,is,idx]:a[u].vc){
        is=(__builtin_popcount(dep[h])<=1);
        Q[idx].is=is;
    }   
    if(!keep){
        add(u,fa,-1,0,depth);
    }
}
void sol() {
    int n,m;
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        int p;cin>>p;
        e[p].push_back(i);
    }
    for(int i=1;i<=n;i++) cin>>zi[i];
    a.assign(n+1,Info());
    for(int i=0;i<m;i++){
        int v,h;
        cin>>v>>h;
        a[v].vc.push_back(Query(v,h,i));
        Q[i].u=v,Q[i].h=h,Q[i].idx=i;
    }
    dfs1(1,0);
    dfs2(1,0,1,1);
    for(int i=0;i<m;i++){
        cout<<(Q[i].is?"Yes\n":"No\n");
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