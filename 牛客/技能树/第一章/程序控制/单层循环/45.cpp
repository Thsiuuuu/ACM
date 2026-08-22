#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long  long  
void sol() {
    int n;
    cin>>n;
    n=llabs(n);
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
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