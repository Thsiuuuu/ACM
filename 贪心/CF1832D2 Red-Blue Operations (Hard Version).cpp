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
const int N=2e5+3;
int n,q,a[N];
ll b[N],mnb[N],sum[N],pb[N];
bool ck(ll x,ll k){
    if(n==1) return ((k&1)?(k-(k-1)/2):(-k/2))+a[1]>=x;
    auto it = lower_bound(a+1,a+1+n,x);
    if(it==a+1) return true;
    it--;
    int idx=it-a;
    if(mnb[idx]+k<x) return false;
    if(n>=k) return true;
    if((k-idx)&1 ){
        return idx^n;
    }
    else if(n-idx>=2) return true;
    else return pb[idx]+k*idx+sum[n]-sum[idx]-(k-idx)/2>=n*x;
}
void sol() {
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    // for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++){
        b[i]=a[i]-i+1;
        mnb[i]=((i>1)?min(mnb[i-1],b[i]):b[i]);
        sum[i]=sum[i-1]+a[i];
        pb[i]=pb[i-1]+b[i];
    }
    while(q--){
        int k;cin>>k;
        ll mid,l=-1e18,r=1e18,ans;
        while(l<=r){
            mid=(l+r)>>1;
            if(ck(mid,k)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        cout<<ans<<' ';
    }
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