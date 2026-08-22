#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define pll pair<ll,ll>
#define double long double

const int N=1010;
int but[N];

void sol() {
    int n;  cin>>n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    ll k=0;
    for(int i=2;i<=n;i++){
        if(a[i]<=a[i-1]){
            k=a[i-1]/(a[i]-1);
            break;
        }
    } 
    if(!k) k=max(a[2]-a[1],a[n]/(a[2]-a[1]));
    cout<<k<<'\n';
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