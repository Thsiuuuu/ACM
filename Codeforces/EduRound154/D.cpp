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
void sol() {
    int n;cin>>n;
    VI a(n+1),pre(n+1,0),suf(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) pre[i]=pre[i-1]+(a[i-1]<=a[i]);
    for(int i=n-1;i>=1;i--) suf[i]=suf[i+1]+(a[i]>=a[i+1]);
    int ans=1e9;
    for(int i=1;i<=n+1;i++){
        int cnt=0;
        if(i-1>=1) cnt+=pre[i-1];
        if(i<n) cnt+=suf[i];
        if(i>1) cnt+=1;
        ans=min(ans,cnt);  
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