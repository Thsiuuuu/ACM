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
const int N=5e5+10;
vector<pii> e[N];
int siz[N],son[N];
ll mask[N],ans[N],dep[N],bit[(1<<22)+5];
void add(int u,int fa,int val,int ban){
    if(val==1){
        bit[mask[u]]=max(bit[mask[u]],dep[u]);
    }else{
        bit[mask[u]]=-1;
    }
    for(auto&[v,w]:e[u]){
        if(v==fa||v==ban) continue;
        add(v,u,val,ban);
    }
}

void query(int rt,int u,int fa){
    if(bit[mask[u]]!=-1){
        ans[rt]=max(ans[rt],bit[mask[u]]+dep[u]-2*dep[rt]);
    }
    for(int i=0;i<22;i++){
        int aft=((1<<i)^mask[u]);
        if(bit[aft]!=-1){
            ans[rt]=max(ans[rt],dep[u]+bit[aft]-2*dep[rt]);
        }
    }
    for(auto&[v,w]:e[u]){
        query(rt,v,u);
    }
}

void dfs1(int u,int fa){
    siz[u]=1,son[u]=0;
    dep[u]=dep[fa]+1;
    for(auto&[v,w]:e[u]){
        if(fa^v){
            mask[v]=(mask[u]^(1<<w));
            dfs1(v,u);
            siz[u]+=siz[v];
            if(siz[v]>siz[son[u]]) son[u]=v;
        }
    }
}

void dfs2(int u,int fa,bool keep){
    for(auto&[v,w]:e[u]){
        if(v==fa||v==son[u]) continue;
        dfs2(v,u,false);
        ans[u]=max(ans[u],ans[v]);
    }
    if(son[u]){
        dfs2(son[u],u,true);
        ans[u]=max(ans[u],ans[son[u]]);
        if(bit[mask[u]]!=-1){
            ans[u]=max(ans[u],bit[mask[u]]+dep[u]-2*dep[u]);
        }
        for(int i=0;i<22;i++){
            int aft=((1<<i)^mask[u]);
            if(bit[aft]!=-1){
                ans[u]=max(ans[u],dep[u]+bit[aft]-2*dep[u]);
            }
        }
    }
    bit[mask[u]]=max(bit[mask[u]],dep[u]);
    for(auto&[v,w]:e[u]){
        if(v!=fa&&v!=son[u]){
            query(u,v,u);
            add(v,u,1,son[u]);
        }
    }
    if(!keep){
        add(u,fa,-1,0);
    }
}

void sol() {
    int n;cin>>n;
    for(int i=2;i<=n;i++){
        int p;char c;
        cin>>p>>c;
        e[p].push_back({i,(c-'a')});
    }
    for(int i=0;i<=(1<<22);i++) bit[i]=-1;
    dfs1(1,0);
    dfs2(1,0,1);
    for(int i=1;i<=n;i++){
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