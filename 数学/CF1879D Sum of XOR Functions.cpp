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
const ll mod=998244353;
const int N=3e5+10;
ll cnt[2],n,a[N],sum[2];
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int s=0;
    ll ans=0;
    for(int i=31;i>=0;i--){
        sum[0]=sum[1]=cnt[1]=0,cnt[1]=1;
        for(int r=1;r<=n;r++){
            s^=a[r];
            int x=(s>>i)&1;
            ans=(((ans+cnt[!x]*r%mod)%mod-sum[!x]+mod)%mod)*(1<<i)%mod;
            cnt[x]++,sum[x]=(sum[x]+(r-1+mod)%mod)%mod;
        }
    }   
    cout<<ans;
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