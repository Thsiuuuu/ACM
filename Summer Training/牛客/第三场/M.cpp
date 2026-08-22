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
const int N=5e5+10;
VI e[N];
VL C,P,Q,mu,w,a,b,S,B;
int n,s,t;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
void dfs1(int u,int fa){
    for(int v:e[u]){
        if(v^fa){
            dfs1(v,u);
            P[u]+=(a[v]*ksm(e[u].size()-1+a[v],mod-2)%mod);
            P[u]%=mod;
            C[u]+=b[v];
            C[u]%=mod;
        }
    }
    for(int v:e[u]){
        if(v^fa){
            Q[u]+=(a[v]*(((e[u].size()-1+C[u])%mod-b[v]+mod)%mod)%mod*ksm((e[u].size()-1+a[v])%mod,mod-2)%mod)%mod;
            Q[u]%=mod;
        }
    }
    if(e[u].size()==1){
        a[u]=b[u]=1;
    }else{
        mu[u]=P[u]*ksm((1-P[u]+mod)%mod,mod-2)%mod;
        w[u]=Q[u]*ksm((1-P[u]+mod)%mod,mod-2)%mod;
        a[u]=mu[u]*ksm(e[u].size()-1,mod-2)%mod;
        b[u]=(1+(w[u]+C[u])%mod*ksm(e[u].size()-1,mod-2)%mod)%mod;
    }
}
void dfs2(int u,int fa){
    if(fa==t){
        B[u]=0;
    }else if(fa^t){
        B[u]=((S[fa]+((B[fa]+(e[fa].size()-1+C[fa])%mod)%mod+(mod-b[u])%mod)%mod)%mod)%mod*((ksm((e[fa].size()-1+a[u])%mod,mod-2))%mod)%mod;
    }
    S[u]=(mu[u]*B[u]%mod+w[u])%mod;
    for(int v:e[u]){
        if(fa^v){
            dfs2(v,u);
        }
    }
}

void sol() {
    cin>>n>>s>>t;
    C.assign(n+1,0);
    P.assign(n+1,0);
    Q.assign(n+1,0);
    mu.assign(n+1,0);
    w.assign(n+1,0);
    a.assign(n+1,0);
    b.assign(n+ 1,0);
    S.assign(n+1,0);
    B.assign(n+1,0);
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
    for(int i=2;i<=n;i++){
        int fa;cin>>fa;
        e[fa].push_back(i);
        e[i].push_back(fa);
    }   
    if(s==t){
        cout<<"0\n";
        return ;
    }
    e[t].push_back(0);
    dfs1(t,0);
    dfs2(t,0);
    ll ans=(1+(((B[s])%mod+S[s])%mod+C[s])%mod*ksm(e[s].size(),mod-2))%mod;
    cout<<ans<<'\n';
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