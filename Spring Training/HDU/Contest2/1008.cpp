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
    int n;cin>>n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    ll mn=*min_element(a.begin(),a.end());
    int ans;
    for(int i=0;i<=n;i++){
        if(a[i]==mn){
            ans=i;
            break;
        }
    }
    ans++;
    if(ans>n) ans=1;
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