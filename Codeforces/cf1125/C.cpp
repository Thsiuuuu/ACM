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
const int N=3e5+10;
int n;
ll a[N];
bool ck(int x,int y){
    return a[x]+a[x+2]-a[x+4]==a[y]+a[y+2]-a[y+4];
}
void sol() {
    map<ll,ll> mp;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for(int i=n-4;i>=1;i--){
        ans+=mp[a[i]+a[i+2]-a[i+4]];
        if(i+6<=n&&ck(i,i+2)) ans--;
        if(i+8<=n&&ck(i,i+4)) ans--;
        mp[a[i]+a[i+2]-a[i+4]]++;
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