#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
void sol() {
    int n,k;
    cin>>n>>k;
    int year=n;
    int ori=n;
    for(;n<k;year++,n+=(year)){

    }
    cout<<(year-ori);
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