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
const int N=2e5+10;
ll n,k;
ll a[N],b[N],c[N],cnt[N],rem[N];
const ll INF=1e9+3,NF=2e18;
bool ck(ll mid){
    i128 kk=k;
    for(int i=1;i<=n;i++){
        if(a[i]+b[i]+c[i]>=mid) continue;
        if(a[i]+b[i]+c[i]<mid){
            if(a[i]==b[i]&&b[i]==c[i]) return false;
            kk-=cnt[i];
            kk-=mid-rem[i];
        }
    }
    return kk >=0;
}
void sol() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    ll l,r=NF,ans;
    i128 mid;
    for(int i=1;i<=n;i++){
        if(i==1) l=a[i]+b[i]+c[i];
        else l=min(l,a[i]+b[i]+c[i]);
        if(a[i]<=b[i]&&b[i]<=c[i]){
            ll number=min(c[i]-b[i],b[i]-a[i]);
            // cout<<number<<'\n';
            // cout<<b[i]<<" "<<c[i]<<" "<<a[i]<<'\n';
            rem[i]=a[i]+b[i]+c[i]-number-1,cnt[i]=number+1;
        }else{
            cnt[i]=0,rem[i]=a[i]+b[i]+c[i];
        }
    }    
    ans=l;
    // cout<<"##########\n";
    // for(int i=1;i<=n;i++){
    //     cout<<rem[i]<<" "<<cnt[i]<<'\n';
    // }
    while(l<=r){
        mid=(l+r)>>1;
        if(ck(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
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