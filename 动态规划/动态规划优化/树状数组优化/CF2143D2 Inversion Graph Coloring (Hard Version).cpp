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
const ll mod=1e9+7;
struct BIT {
    int n;
    vector<ll> a, b;
    BIT(int n = 0) {
        init(n);
    }
    void init(int n_) {
        n = n_;
        a.assign(n + 2, 0);
        b.assign(n + 2, 0);
    }
    void add(int p, ll v) {
        for (int i = p; i <= n; i += i & -i) {
            a[i] =(a[i]+v)%mod;
            b[i] =(b[i]+1LL * p * v%mod)%mod;
        }
    }
    // 区间加
    void rangeAdd(int l, int r, ll v) {
        add(l, v);
        add(r + 1, -v);
    }
    // 前缀和
    ll query(int p) {
        ll res = 0;
        for (int i = p; i; i -= i & -i) {
            res = (res+1LL * (p + 1) * a[i]%mod - b[i]+mod)%mod;
        }
        return res;
    }
    // 区间和
    ll rangeQuery(int l, int r) {
        return (query(r) - query(l - 1)+mod)%mod;
    }
};
void sol() {
    int n;cin>>n;
    VL a(n+1,0);
    VLL f(n+2,VL(n+2,0));
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<BIT> r(n+2,BIT(n+2)),c(n+2,BIT(n+2));
    f[1][1]=1;
    r[1].rangeAdd(1,1,1);
    c[1].rangeAdd(1,1,1);
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n+1;k++){
            ll sum=c[k].query(a[i]+1);
            f[a[i]+1][k]=(f[a[i]+1][k]+sum)%mod;
            c[k].rangeAdd(a[i]+1,a[i]+1,sum);
            r[a[i]+1].rangeAdd(k,k,sum);
        }
        for(int j=a[i]+2;j<=n+1;j++){
            ll sum=r[j].query(a[i]+1);
            f[j][a[i]+1]=(f[j][a[i]+1]+sum)%mod;
            r[j].rangeAdd(a[i]+1,a[i]+1,sum);
            c[a[i]+1].rangeAdd(j,j,sum);
        }
    }
    ll ans=0;
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=n+1;j++){
            ans=(ans+f[i][j])%mod;
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