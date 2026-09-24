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
ll ans,mod,fac=1,n,a,b,f[11];
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
ll C(ll b,ll k){
    if(b-k<0) return 0;
    ll res=1;
    for(ll x=n+b-k;x>b-k;x--){
        res*=x;
        res%=mod;
    }
    return res;
}
void dfs(int step,int op,ll pw){
    if(step==n){
        if(pw<=b){
            ans=(ans+(op*((C(b,pw)-C(a-1,pw)+mod)%mod)%mod+mod)+mod)%mod;
        }
        return ;
    }   
    dfs(step+1,op,pw);
    dfs(step+1,-op,pw+f[step]+1);
}
void sol() {
    cin>>n>>a>>b;
    for(int i=0;i<n;i++) cin>>f[i];
    for(int i=1;i<=n;i++) fac=fac*i;
    mod=fac*2004;
    dfs(0,1,0);
    cout<<ans/fac;
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