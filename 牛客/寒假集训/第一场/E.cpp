#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mx=INT32_MIN;//最大值有可能是负数
    for(int i=0;i<n-1;i++){
        mx=max(mx,a[i]+a[i+1]);
    }
    mx=max(mx,k+a[0]);
    mx=max(mx,k+a[n-1]);
    cout<<mx<<'\n';
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