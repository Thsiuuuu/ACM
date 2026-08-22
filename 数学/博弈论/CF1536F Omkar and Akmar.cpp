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
const ll mod=1e9+7;
const int N=1e6+10;
ll fac[N],inv[N];
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
    for(int i=2;i<N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N-1]=ksm(fac[N-1],mod-2);
    for(int i=N-2;i>=2;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(ll n,ll m){
    if(m>n||m<0||n<0) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod; 
}
void sol() {
    int n;cin>>n;
    ll ans=0;
    for(int x=(n+1)/2;x<=n;x++){
        if(x&1) continue;
        int y=n-x;
        ans+=(2*fac[x]%mod*((C(x,y)+C(x-1,y-1))%mod)%mod);
        ans%=mod;
    }
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