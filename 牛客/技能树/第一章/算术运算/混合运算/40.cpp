#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
void sol() {
    int n;
    cin>>n;
    int sum=0;
    sum+=(n/12)*4+2;
    cout<<sum;
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