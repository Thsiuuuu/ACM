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
int a[1010][1010],n,m;
unordered_map<int,ll> sum,cnt;
void sol() {
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=i*cnt[a[i][j]]-sum[a[i][j]];
        }
        for(int j=0;j<m;j++) cnt[a[i][j]]++,sum[a[i][j]]+=i;
    }
    sum.clear(),cnt.clear();
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            ans+=j*cnt[a[i][j]]-sum[a[i][j]];
        }   
        for(int i=0;i<n;i++) cnt[a[i][j]]++,sum[a[i][j]]+=j;
    }
    cout<<ans*2;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}