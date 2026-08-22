#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define double long double
#define i128 __int128_t
#define ull unsigned long long  



void sol() {
    ll n,m;cin>>n>>m;
    if((n+m)&1){
        if(n&1) swap(n,m);
        cout<<(m)/2*n+n/2;
    }else{
        if(n&1) cout<<(m)/2*n+n/2+1;
        else cout<<max(m*(n-2)/2,n*(m-2)/2);
    }
    cout<<'\n';
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