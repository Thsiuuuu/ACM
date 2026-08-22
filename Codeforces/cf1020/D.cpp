#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    int n,m;
    cin>>n>>m;
    vector<ll> a(n+1),b(m+1),p(m+1,1e18),s(m+1,-1e18);
    
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1,j=1;i<=n&&j<=m;i++){
        if(a[i]>=b[j]){
            p[j++]=i;
        }
    }
    for(int i=n,j=m;i>=1&&j>=1;i--){
        if(a[i]>=b[j]){
            s[j--]=i;
        }
    }
    if(m==1){
        if(p[1]<=n) cout<<"0\n";
        else cout<<b[1]<<'\n';
        return;
    }
    ll ans=1e18;
    if(s[2]>=1) ans=min(ans,b[1]);
    if(p[m-1]<=n) ans=min(ans,b[m]);
    for(int i=2;i<=m-1;i++){
        if(p[i-1]<s[i+1]) ans=min(ans,b[i]);
    }
    if(p[m]<=n) ans=0;
    if(ans==1e18) ans=-1;
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