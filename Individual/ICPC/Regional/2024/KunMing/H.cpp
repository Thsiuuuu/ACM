#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
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

#define ld long double
const ld PI=acos(-1),eps=1e-7;
void sol() {
    int n,k;cin>>n>>k;
    vector<ld> a;
    for(int i=0;i<n;i++){
        ld x,y;cin>>x>>y;
        a.push_back(atan2(y,x));
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        a.push_back(a[i]+2*PI);
    }
    ld ans=0;
    for(int i=0,r=0;i<a.size();i++){
        while(r+1-i+1<=k+1&&r+1<a.size()) r++;
        ans=max(ans,a[r]-a[i]);
    }
    cout<<fixed<<setprecision(10)<<ans<<'\n';
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