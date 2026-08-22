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
const int N=5202;
const ll mod=998244353;
VI e[N];
ll fac[N],inv[N];
pair<ll,ld> f[N][N],A[N]
,
// ;
B[N];
int n;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
void init(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N-1]=ksm(fac[N-1],mod-2);
    for(int i=N-2;i>=2;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
void dfs1(int u,int fa,int p){
    if(e[u].size()==1&&u!=1) A[u]={inv[e[fa].size()],1.0/e[fa].size()};
    else{
        pair<ll,ld> X={0,0};
        // ,S={0,0};
        for(int v:e[u]){
            if(v==fa) continue;
            dfs1(v,u,p);
            if(v^p){
                X={(X.first+A[v].first*inv[e[v].size()]%mod)%mod,X.second+A[v].second/e[v].size()};
                // auto [fir,sec]=X;
                // cout<<fir<<" "<<sec<<'\n';
                // S={(S.first+B[v].first*inv[e[v].size()]%mod)%mod,S.second+B[v].second/e[v].size()};
            }
        }
        // cout<<1/e[fa].size()<<'\n';
        // cout<<u<<" "<<A[u].first<<" "<<A[u].second<<'\n';
        ll invX=ksm((1-X.first+mod)%mod,mod-2);
        // cout<<u<<" "<<invX<<'\n';
        // cout<<u<<" "<<" "<<X.first<<" "<<X.second<<'\n';
        A[u]={invX*inv[e[fa].size()]%mod,1/(1-X.second)/e[fa].size()};
        // B[u]={invX*S.first%mod,1/(1-X.second)*S.second};
    }
}
void dfs2(int u,int fa,int p){
    if(u!=1)    f[u][p]={
                    (A[u].first*f[fa][p].first%mod
                        +B[u].first
                    )%mod,
                    A[u].second*f[fa][p].second
                    +B[u].second
                    };
    for(int v:e[u]){
        if(v==fa) continue;
        dfs2(v,u,p);
    }
}
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++){
        e[i].clear();
        for(int j=1;j<=n;j++){
            f[i][j]={0,0};
        }
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    pair<ll,ld> ans={0,0};
    for(int p=1;p<=n;p++){
        if(e[p].size()==1){
            for(int i=1;i<=n;i++) A[i]=B[i]={0,0};
            f[1][p]={1,1};
            dfs1(1,0,p);
            dfs2(1,0,p);
            for(int i=1;i<=n;i++){
                if(e[i].size()==1&&i!=p){
                    // cout<<f[i][p].second<<'\n';
                    // if(f[i][p].first==665496236){
                    //     cout<<i<<" "<<p<<'\n';
                    // }
                    if(ans.second<f[i][p].second) ans=f[i][p];
                }
            }
        }
    }

    cout<<ans.second<<'\n';
    // cout<<ans.first<<'\n';
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