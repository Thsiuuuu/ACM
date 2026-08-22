#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define int long long 
#define double long double



void sol() {
    int n;
    cin>>n;
    vector<int> f(n+1,0),a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    for(int i=2;i<n;i++){
        int pre=f[i-1]-f[i];
        int suf=f[i]-f[i+1];
        a[i]=(pre-suf)>>1;
    }
    int sum=0ll;
    for(int i=1;i<n;i++){
        sum+=(i-1)*a[i];
    }
    a[n]=(f[1]-sum)/(n-1);
    sum=0ll;
    for(int i=n;i>1;i--){
        sum+=(n-i)*a[i];
    }
    a[1]=(f[n]-sum)/(n-1);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
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