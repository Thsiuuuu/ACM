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
struct BIT {
    int n;
    vector<ll> a;

    BIT(int n = 0) {
        init(n);
    }

    void init(int n_) {
        n = n_;
        a.assign(n + 2, 0);
    }

    // 单点加
    void add(int p, ll v) {
        for (int i = p; i <= n; i += i & -i) {
            a[i] = (a[i] + v) ;
        }
    }

    // 前缀和
    ll query(int p) {
        ll res = 0;
        for (int i = p; i; i -= i & -i) {
            res = (res + a[i]);
        }
        return res;
    }

    // 区间和
    ll rangeQuery(int l, int r) {
        return (query(r) - query(l - 1));
    }
};
void sol() {
    int n;cin>>n;
    VL a(n+1,0),b;
    VLL all(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        all[min((ll)n,max(a[i],(ll)i))].push_back(i);
    }
    // b=a;
    ll ans=0;
    BIT bit(n+1);
    for(int i=n;i>=1;i--){
        ans+=bit.rangeQuery(min((ll)i,max(a[i],(ll)i+1)),n);
        bit.add(min(a[i],(ll)n),1);
    }
    bit.init(n+1);
    int p=n;
    for(int i=n;i>=1;i--){
        while(p&&p>=i+1){
            bit.add(min(a[p],(ll)n),1); 
            p--;
        }
        for(int j=0;j<all[i].size();j++){
            if(i<n){
                ans-=bit.rangeQuery(all[i][j],n);
            }
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