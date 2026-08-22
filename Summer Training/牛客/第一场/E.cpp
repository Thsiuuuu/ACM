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
const int N=2e5+10;
ll p[N];
ll ans;
void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++){
        // ans-=((n-i)*p[i]);
        // ans+=((n-i)*p[n-i+1]);
        ans+=(2*i-n-1)*p[i];
    }
    cout<<ans;
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