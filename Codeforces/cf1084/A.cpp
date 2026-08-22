#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
#define ll long long 
#define double long double
#define i128 __int128_t

void sol() {
    int n;
    cin>>n;
    int mx=0;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        // int x;
        cin>>a[i];
        mx=max(a[i],mx);
    }
    int number=0;
    for(int i=1;i<=n;i++){
        if(mx==a[i]) number++;
    }
    cout<<number<<'\n';
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