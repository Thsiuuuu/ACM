#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  




void sol() {
    ll n,m;cin>>n>>m;
    ll sum=0;
    for(int i=0,x;i<m;i++){
        cin>>x;
        sum+=x;
    } 
    cout<<max(0ll,sum-n*(m-1));
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