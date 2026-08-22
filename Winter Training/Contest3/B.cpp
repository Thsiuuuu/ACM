#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long
const int mod=1e9+7;

void sol() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    cout<<a[0]<<" ";
    int mul=1;
    for(int i=0;i<n;i++){
        mul=(mul*(a[i]/a[0]))%mod;
    }
    cout<<mul;
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