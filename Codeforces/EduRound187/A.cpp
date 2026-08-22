#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
void sol() {
    int n,m,d;
    cin>>n>>m>>d;
    int ans=0;
    if(m>d){
        cout<<n<<'\n';
        return ;
    }
    int f=d/m+1;
    if(n%f!=0) ans=n/f+1;
    else ans=n/f;
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