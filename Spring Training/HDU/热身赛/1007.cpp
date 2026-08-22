#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long
#define double long double 
#define pii pair<ll,ll>

// int gcd(int a,int b){
//     return b?gcd(b%a,a):a;
// }

void sol() {
    int n;
    cin>>n;
    vector<ll> a(n+1,0),pre(n+1,0),suf(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    pre[1]=a[1],suf[n]=a[n];
    for(int i=2;i<=n;i++) pre[i]=max(pre[i-1],0ll)+a[i];
    for(int i=n-1;i>=1;i--) suf[i]=max(suf[i+1],0ll)+a[i];
    for(int i=2;i<=n;i++) pre[i]=max(pre[i],pre[i-1]);
    for(int i=n-1;i>=1;i--) suf[i]=max(suf[i],suf[i+1]);
    ll ans=INT64_MIN;
    for(int i=3;i<=n-2;i++){
        ans=max(ans,a[i]+pre[i-2]+suf[i+2]);
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}