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
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
void sol() {
    int n;cin>>n;
    VL a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll g=0;
    for(int i=1;i<n;i++){
        g=gcd(g,llabs(a[i]-a[0]));
    }
    if(g==0) cout<<"infinite\n";    
    else{
        ll r=a[0]%g;
        cout<<g<<" "<<g/gcd(g,r)<<'\n';
    }
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