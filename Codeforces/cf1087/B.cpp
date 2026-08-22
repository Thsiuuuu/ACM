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
    int n;cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        ll sum1=0,sum2=0;
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i]) sum1++;
            if(a[j]>a[i]) sum2++;
        }
        cout<<max(sum1,sum2)<<" ";
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