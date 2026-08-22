#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
void sol() {
    int n;
    cin>>n;
    vector<ll> a(n);
    map<ll,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    // ll Mx=0,Mxidx;
    // for(const auto&[key,val]:mp){
    //     if(val>Mx) Mxidx=key,Mx=val;
    // }
    ll ans=1e9;
    ll s1,s2;
    s1=s2=0;
    for(const auto&[key,val]:mp){
        ans=min(ans,max(s1,n-s1-val));
        s1+=val;
    }
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