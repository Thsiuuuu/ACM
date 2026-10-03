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
const ll mod=1e9+7;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
void sol(int ts) {
    ll n,k;cin>>n>>k;
    ll ans=ksm(2,n);
    ll sum=1;
    ans=(ans-sum+mod)%mod;
    for(int i=1;i<k;i++){
        sum=(sum*((n-i+1+mod)%mod)%mod*ksm(i,mod-2)%mod);
        ans=(ans-sum+mod)%mod;
    }
    cout<<"Case #"<<ts<<": "<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}