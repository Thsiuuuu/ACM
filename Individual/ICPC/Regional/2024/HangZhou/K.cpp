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
int cal(int i,int m){
    return (i-1+m)/m;
}
void sol() {
    ll n,m,k;cin>>n>>m>>k;
    VL num(n+1,0),cnt(n*m+1,0);
    for(int i=1;i<=n*m;i++){
        int x;cin>>x;
        cnt[i]=max(cnt[i-1],++num[cal(x,m)]);
    }
    ll l=m,r=n*m,mid;
    ll ans;
    while(l<=r){
        mid=(l+r)>>1;
        if(m-cnt[mid]<=k){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
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