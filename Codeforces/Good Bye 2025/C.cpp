#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*



*/
void sol() {
    int n;
    cin>>n;
    vector<int> a(n+1),pre(n+1,0),suf(n+2,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2){
            pre[i]=llabs(a[i])+pre[i-1];
        }
    }
    for(int i=n;i>=2;i--){
        suf[i]=suf[i+1]-a[i];
    }
    int mx=-INT64_MIN;
    for(int i=1;i<=n;i++){
        int ans=suf[i+1]+pre[i-1];
        if(i>1){
            ans+=a[1];
        }
        mx=max(mx,ans);
    }
    cout<<mx<<'\n';
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