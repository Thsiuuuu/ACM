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
const int N=2e5+10;
vector<int> e[N],yue[N];
int siz[N],son[N],cnt[N],mu[N];
ll ans;
void init( ){
    mu[1]=1;
    vector<bool> vis(N+1,false);
    vector<int> primes;
    for(ll i=2;i<N;i++){
        if(!vis[i])
            primes.push_back(i),mu[i]=-1;
        for(int j=0;j<primes.size()&&primes[j]*i<N;j++){
            vis[primes[j]*i]=true;
            if(i%primes[j]==0){
                break;
            }
            mu[primes[j]*i]=-mu[i];
        }
    }
    for(int i=1;i<=N-10;i++){
        for(int x=i;x<=N-10;x+=i){
            yue[x].push_back(i);
            // bei[i]++;
        }
    }
}
void fang(int u,int fa,int is){
    for(int x:yue[u]){
        cnt[x]+=is;
    }
    for(int v:e[u]){
        if(v^fa){
            fang(v,u,is);
        }
    }
}
void add(int u,int fa,int is,int ban,int uu){
    if(is==1){
        if(u^uu){
            for(int d:yue[u]){
                if(d%uu==0) ans+=cnt[d]*mu[d/uu];
            }
        }
        for(int v:e[u]){
            if(v==fa||v==ban) continue;
            add(v,u,is,ban,uu);
            if(u==uu) fang(v,u,is);
        }
    }
    else fang(u,fa,is);
}
void dfs1(int u,int fa){
    siz[u]=1,son[u]=0;
    for(int v:e[u]){
        if(v^fa){
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
    if(son[u]) dfs2(son[u],u,true);
    add(u,fa,1,son[u],u);
    ans+=cnt[u]*mu[1];
    for(int x:yue[u]){
        cnt[x]++;
    }
    if(keep==false){
        add(u,fa,-1,0,u);
    }
}

void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans=0;
    dfs1(1,0);
    dfs2(1,0,false);
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    init();
    while (t--) {
        sol();
    }
    return 0;
}