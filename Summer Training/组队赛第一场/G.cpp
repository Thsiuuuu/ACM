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
const ll mod=998244353;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
const int N=1e6+10;
ll num[N];
void sol() {
    int n;cin>>n;
    VLL sn(n+1);
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            ll x;cin>>x;
            sn[i].push_back(x);
            num[x]++;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(const auto x:sn[i]){
            ans=(ans+ksm(n*sn[i].size()%mod*n%mod,mod-2)*num[x]%mod)%mod;
        }
    }
    cout<<ans;
    // ll up=0,dn=0;
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<sn[i].size();j++){
    //         cout<<i<<" "<<j<<'\n';
    //         up=(up+num[sn[i][j]])%mod;
    //         cout<<"? "<<up<<" "<<dn<<'\n';
    //     }
    //     dn=(dn+sn[i].size()*n%mod)%mod;
    // }
    // cout<<(up*ksm(dn,mod-2)%mod);
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