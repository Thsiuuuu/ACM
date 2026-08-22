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

const int M=2e5+10;
const ll mod=1e9+7;
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
    fac[0]=fac[1]=1;
    for(int i=2;i<M;i++) fac[i]=fac[i-1]*i%mod;
    inv[M-1]=ksm(fac[M-1],mod-2);
    for(int i=M-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

ll C(ll n,ll m){
    if(m<0||m>n) return 0;
    else return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

void sol() {
    ll n,m;
    cin>>n>>m;
    ll x,y;
    cin>>y>>x;
    ll ans=0;
    for(int i=1;i<=y;i++){
        ans=(ans+C(x+n-1-i,x-1)*C(m-x+i-2,m-1-x)%mod)%mod;
    }
    ans=(C(n+m-2,n-1)-ans+mod)%mod;
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    init();
    while (t--) {
        sol();
    }
    return 0;
}