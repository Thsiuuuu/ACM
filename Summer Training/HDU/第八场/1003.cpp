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
const ll mod=998244353;
const int M=2e5+10;
ll inv[M],fac[M];

ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}

void init(){
    fac[0]=fac[1]=inv[1]=inv[0]=1;
    for(int i=2;i<M;i++) fac[i]=fac[i-1]*i%mod;
    inv[M-1]=ksm(fac[M-1],mod-2);
    for(int i=M-2;i>=2;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

ll C(ll n,ll m){
    if(m>n||m<0||n<0) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod; 
}
void sol() {
    int n,q;cin>>n>>q;
    ll B=sqrt(n);
    VLL f(B+1,VL(n+1,0));
    for(int k=1;k<=B;k++){
        for(int i=1;i<=n;i++){
            if(i<=k) f[k][i]=i+1;
            else f[k][i]=(f[k][i-1]+f[k][i-k])%mod;
        }
    }
    auto cal=[&](ll m,ll k){
        if(m<=0) return 1ll;
        ll ans=0;
        for(ll c=0;m-(k-1)*(c-1)>0;c++){
            ans+=C(m-(k-1)*(c-1),c);
            ans%=mod;
        }
        return ans;
    };
    while(q--){
        int x,k;cin>>x>>k;
        ll ans=0;
        if(k<=B){
            ans=f[k][n];
            ll L=(x<=k)?1:f[k][x-k];
            ll R=(n-x-k+1<=0)?1:f[k][n-x-k+1];
            ans=(ans-L*R%mod+mod)%mod;    
        }else{
            ans=(cal(n,k)-cal(x-k,k)*cal(n-x-k+1,k)%mod+mod)%mod;
        }
        cout<<ans<<'\n';
    }
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