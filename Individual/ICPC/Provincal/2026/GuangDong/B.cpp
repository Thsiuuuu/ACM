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
void sol() {
    ll x;cin>>x;
    ll ans=1e18;
    ll a=sqrt(x),b,c;
    for(int i=0;i<500&&a>=0;i++){
        ll b=ceil(1.0l*x/(a+1)),c=x-a*b;
        if(min({a,b,c})>=0) ans=min(ans,max({a,b,c})-min({a,b,c}));
        b=floor(1.0l*x/(a+1)),c=x-a*b;
        if(min({a,b,c})>=0) ans=min(ans,max({a,b,c})-min({a,b,c}));
        a--;
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