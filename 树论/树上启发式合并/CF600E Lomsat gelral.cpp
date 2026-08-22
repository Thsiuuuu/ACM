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
int c[N],siz[N],son[N];
ll cnt[N],ans[N];
ll Mx,sum;
void add(int u,int fa,int val,int ban){
    int col=c[u];
    if(val==1){
        cnt[col]++;
        if(cnt[col]>Mx){
            Mx=cnt[col];
            sum=col;
        }else if(cnt[col]==Mx){
            sum+=col;
        }
    }else{
        cnt[col]--;
    }
    for(int v:e[u]){
        if(v==fa||v==ban) continue;
        add(v,u,val,ban);
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

void dfs2(int u,int fa,bool keep){
    for(int v:e[u]){
        if(v==fa||v==son[u]) continue;
        dfs2(v,u,false);
    }
    if(son[u]){
        dfs2(son[u],u,true);
    }
    add(u,fa,1,son[u]);
    ans[u]=sum;
    if(!keep){
        add(u,fa,-1,0);
        Mx=0,sum=0;
    }
}

void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
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