#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
void sol() {
    int a,b,c;
    cin>>a>>b>>c;
    int s=2*(a*b+b*c+c*a);
    int v=a*b*c;
    cout<<s<<'\n'<<v;
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