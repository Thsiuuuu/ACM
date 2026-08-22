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
ll cal(ll a,ll b){
    return (a%b)?a/b:a/b-1;
}
void sol() {
    ll k,n,a,b;cin>>k>>n>>a>>b;
    ll l=cal(k,a),r=cal((k-n*b),(a-b));
    ll mi=min(l,r);
    // cout<<l<<" "<<r<<'\n';
    if(k<=n*b) mi=-1;
    // if(mi<=0) mi=-1;
    cout<<min(mi,n)<<'\n';
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