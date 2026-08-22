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
const ll mod=998244353;
const int N=2e5+10;
ll ksm(ll a,ll b){
    a=a%mod;
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
vector<int> e[N];
int n,st,ed;
VL fa(N,0),f(N,0),A(N,0),B(N,0);
void dfs1(int u){
    if(u!=ed&&e[u].size()==1){
        A[u]=(fa[u]==ed)?0:ksm(e[fa[u]].size(),mod-2);
        B[u]=(u==st);
        return ;
    }
    ll s1=0,s2=0;
    for(int v:e[u]){
        if(v^fa[u]){
            fa[v]=u;
            dfs1(v);
            s1=(s1+A[v]*ksm(e[v].size(),mod-2)%mod)%mod,
            s2=(s2+B[v]*ksm(e[v].size(),mod-2)%mod)%mod;
        }
    }
    if(u^ed){
        ll base=ksm((1-s1+mod)%mod,mod-2);
        A[u]=(fa[u]==ed)?0:ksm(e[fa[u]].size(),mod-2)*base%mod,
        B[u]=((u==st)+s2)%mod*base%mod;  
    }
}

void dfs2(int u){
    if(u^ed){
        f[u]=(A[u]*f[fa[u]]%mod+B[u])%mod;
    }
    for(int v:e[u]){
        if(v^fa[u]){
            dfs2(v);
        }
    }
}


void sol() {
    cin>>n>>st>>ed;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    f[ed]=1;
    dfs1(ed);
    dfs2(ed);
    for(int i=1;i<=n;i++){
        cout<<f[i]<<" ";
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