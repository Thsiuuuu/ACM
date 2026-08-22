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
const int N=1e5+10;
vector<int> e[N];
int siz[N],son[N];
int ans[N];
int st[N][21];
int root[N],tot;
VLL dep;
struct Query{
    int id;
    int len;
    Query(){
    }
    Query(int id,int len):id(id),len(len){}
};

vector<vector<Query>> Info(N);

void add(int rt,int u,int fa,int val,int ban,int depth){
    if(val==1){
        dep[rt][depth]++;
    }else{
        dep[rt][depth]--;
    }
    for(int v:e[u]){
        if(v==fa||v==ban) continue;
        add(rt,v,u,val,ban,depth+1);
    }
}
void dfs1(int u,int fa,int& MxD,int depth){
    st[u][0]=fa;
    siz[u]=1,son[u]=0;
    MxD=max(MxD,depth);
    for(int i=0;i<20;i++){
        st[u][i+1]=st[st[u][i]][i];
    }
    for(int v:e[u]){
        if(fa^v){
            dfs1(v,u,MxD,depth+1);
            siz[u]+=siz[v];
            if(siz[v]>siz[son[u]]) son[u]=v;
        }
    }
}

void dfs2(int rt,int u,int fa,bool keep,int depth){
    for(int v:e[u]){
        if(v==fa||v==son[u]) continue;
        dfs2(rt,v,u,false,depth+1);
    }
    if(son[u]){
        dfs2(rt,son[u],u,true,depth+1);
    }
    add(rt,u,fa,1,son[u],depth);
    for(auto&[id,len]:Info[u]){
        if(depth+len<=dep[rt].size()) ans[id]=dep[rt][depth+len]-1;
        else ans[id]=0;
        // cout<<id<<" "<<ans[id]<<'\n';
    }
    // cout<<u<<" \n";
    // for(int i=1;i<=6;i++){
    //     cout<<dep[i]<<" ";
    // }
    // cout<<'\n';
    if(!keep){
        add(rt,u,fa,-1,0,depth);
    }
}
void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int r;cin>>r;
        if(!r) root[tot++]=i;
        else{
            e[r].push_back(i);
        }
    }
    for(int i=0;i<tot;i++){
        int MxD=0;
        dfs1(root[i],0,MxD,1);
        // cout<<MxD<<'\n';
        dep.push_back(VL(MxD+1,0));
    }
    int m;cin>>m;
    for(int t=0;t<m;t++){
        int v,p;
        cin>>v>>p;
        int fa=v;
        for(int i=20;i>=0;i--){
            if((p>>i)&1) fa=st[fa][i];
        }
        Info[fa].push_back(Query(t,p));
    }
    for(int i=0;i<tot;i++){
        dfs2(i,root[i],0,1,1);
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
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