#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

const ll mod=998244353;

ll ksm(ll a,ll b){
    a%=mod;
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}


void sol() {
    ll n,k,p;
    cin>>n>>k>>p;
    ll s; 
    if(k%mod!=1) s=(ksm(k,n)-1+mod)%mod*ksm(k-1,mod-2)%mod;
    else s=n%mod;
    // cout<<s<<'\n';
    cout<<(((s-1+mod)*p)%mod+1)%mod<<'\n';
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