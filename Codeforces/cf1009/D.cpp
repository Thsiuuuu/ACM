#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
// #define double long double  
// #define double eps=1e-9;


void sol() {
    int n,m;
    cin>>n>>m;

    vector<ll> x(n),r(n);
    for(int i=0;i<n;i++) cin>>x[i];
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        cin>>r[i];
        for(int cur=x[i]-r[i];cur<=x[i]+r[i];cur++){
            mp[cur]=max(mp[cur],(ll)floor(sqrt(r[i]*r[i]-(cur-x[i])*(cur-x[i]))));
        }
    }
    ll ans=0;
    for(auto [key,val]:mp){
        ans+=(2*val+1);
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