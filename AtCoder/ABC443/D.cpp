#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
void sol() {
    int n;
    cin>>n;
    int sum=0ll;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<sum<<'\n';
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