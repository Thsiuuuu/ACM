#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    int n,m;
    cin>>n>>m;

    vector<ll> a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans=0;
    int l=0,r=m-1;
    for(int i=0;i<n;i++){
        if(llabs(a[i]-b[l])>llabs(a[i]-b[r])){
            ans+=llabs(a[i]-b[l]);
            l++;
        }else{
            ans+=llabs(a[i]-b[r]);
            r--;
        }
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