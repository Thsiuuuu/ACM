#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define double long double
#define i128 __int128_t
#define ull unsigned long long  



void sol() {
    int n;cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    map<int,ll> mp1,mp2;
    mp1[a[1]]++;mp2[0]++;
    ll ans=0;
    for(int i=2;i<=n;i++){
        ll tmp=0;
        if(i&1){
            if(mp1.count(a[i])) tmp+=mp1[a[i]];
            mp1[a[i]]++;
        }
        else{
            if(mp2.count(a[i])) tmp+=mp2[a[i]];
            mp2[a[i]]++;
        }

        tmp=i/2-tmp;
        // cout<<i<<" "<<tmp<<'\n';
        ans+=tmp;
    }
    cout<<ans<<" "<<(ll)n*(n+1)/2-ans<<'\n';
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