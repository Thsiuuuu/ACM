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
ll ck(ll x){
    ll sum=0;
    ll y=x;
    while(y){
        sum+=(y%10);
        y/=10;
    }
    return x-sum;
}
void sol() {
    ll n,s;cin>>n>>s;
    ll ans=0;
    for(ll x=s;x<=min(s+162,n);x++){
        if(ck(x)>=s) ans++;
    }
    cout<<max(0ll,n-s-162)+ans;
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