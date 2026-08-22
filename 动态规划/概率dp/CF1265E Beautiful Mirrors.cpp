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

ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        b>>=1,a=a*a%mod;
    }
    return res;
}
void sol() {
    int n;
    cin>>n;
    vector<ll> p(n+1),f(n+1,0);
    for(int i=1;i<=n;i++) cin>>p[i];
    f[0]=0;
    for(int i=1;i<=n;i++){
        f[i]=(f[i-1]+1)%mod*100%mod*ksm(p[i],mod-2)%mod;
    }
    cout<<f[n];
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