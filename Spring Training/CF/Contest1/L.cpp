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

const ll mod=1006903069;

void sol() {
    int n,ka,kb;
    cin>>n>>ka;
    map<pii,ll> mp;
    for(int i=0;i<ka;i++){
        int a,b;
        ll x;
        cin>>a>>b>>x;
        mp[{a,b}]=x;
    }
    ll res=0;
    cin>>kb;
    for(int i=0;i<kb;i++){
        int a,b;
        ll x;
        cin>>a>>b>>x;
        res=(res+mp[{b,a}]*x%mod)%mod;
    }
    cout<<res;
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