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
/*
多测清空，long long ，是否对需要修改的变量赋值了
想不出来注意换思路
注意数据范围，枚举答案是否可行
*/
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
    int n,q;cin>>n>>q;
    VI ans(q,0);
    map<int,int> last;
    vector<pii> a;
    vector<vector<array<int,2>>> Q(n+1);
    BIT bit(n+2);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a.push_back({last[x],i});
        last[x]=i;
    }
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        Q[l].push_back({r,i});
    }
    sort(a.begin(),a.end());
    int p=0;
    for(int i=1;i<=n;i++){
        while(p<a.size()&&a[p].first<i){
            bit.add(a[p++].second,1);
        }
        for(int j=0;j<Q[i].size();j++){
            int id=Q[i][j][1],r=Q[i][j][0];
            ans[id]=bit.rangeQuery(i,r);   
        }
    }
    for(int i=0;i<q;i++) cout<<ans[i]<<'\n';
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