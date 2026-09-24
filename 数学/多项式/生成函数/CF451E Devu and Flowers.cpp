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
ll ksm(ll a, ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
ll f[21],inv,ans,n,s;
ll C(ll i){
    ll res=inv;
    for(ll x=s-i+n-1;x>=s-i+1;x--) res=x%mod*res%mod;
    return res;
}
void dfs(int step,int op,ll i){
    if(step==n){
        if(i<=s){
            ans=(ans+(op*C(i)+mod)%mod)%mod;
        } 
        return ;
    }
    dfs(step+1,op,i);
    dfs(step+1,-op,i+f[step]+1);
}
void sol() {
    cin>>n>>s;
    for(int i=0;i<n;i++) cin>>f[i];
    inv=1;
    for(int i=2;i<=n-1;i++) inv=inv*i%mod;
    inv=ksm(inv,mod-2);
    dfs(0,1,0);
    cout<<ans;
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