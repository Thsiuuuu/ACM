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
    vector<bool> a(n+1,false);
    int ans=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x<=n&&a[x]==false) a[x]=true,ans++;
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