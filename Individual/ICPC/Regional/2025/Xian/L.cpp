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
    VL ans(n+1,0),a(n);
    ll ls,rs,l;ls=rs=l=0;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end(),greater<ll>());
    ls=a[0];
    for(int i=1;i<l+n;i++) rs+=a[i];
    for(int len=n;len>=3;len--){
        int r=l+len;
        if(r<n) rs-=a[r];
        while(l+len<n&&ls>=rs){
            ls=a[l+1];
            rs-=a[l+1];
            rs+=a[l+len];
            l++;
        }
        if(ls<rs) ans[len]=rs+ls;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<'\n';
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