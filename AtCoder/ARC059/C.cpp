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
void sol() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll l=*min_element(a.begin(),a.end()),r=*max_element(a.begin(),a.end());
    ll ans=1e18;
    for(int i=l;i<=r;i++){
        ll tmp=0;
        for(int j=0;j<n;j++){
            tmp+=(a[j]-i)*(a[j]-i);
        }
        ans=min(ans,tmp);
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