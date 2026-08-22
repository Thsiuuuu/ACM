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

ll mod=998244353;
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
    ll m=0;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        m=(m+a[i])%mod;
    }
    for(int i=0;i<n;i++) cin>>b[i];

    ll ans=0;
    ll pre=0,inm=ksm(m,mod-2),pw=ksm(2,mod-2);
    for(int i=0;i<n;i++){
        ans=(ans+a[i]*inm%mod*(pre+b[i]*pw%mod)%mod)%mod;
        pre=(pre+b[i])%mod;
    }
    cout<<ans<<'\n';
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