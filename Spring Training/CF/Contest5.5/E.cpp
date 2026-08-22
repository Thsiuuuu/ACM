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

const ll mod=1e9+7;

ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod,b>>=1;
    }
    return res;
}

void sol() {
    ll n,k;
    cin>>n>>k;
    ll inv=ksm(k,mod-2);
    ll pw=(ksm((k+1),n)-1+mod)%mod;
    cout<<(k+1)*pw%mod*inv%mod<<'\n';
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