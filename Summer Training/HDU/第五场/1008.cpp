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
            a[i] =max(a[i],v);
        }
    }

    // 前缀和
    ll query(int p) {
        ll res = 0;
        for (int i = p; i; i -= i & -i) {
            res = max(res , a[i]);
        }
        return res;
    }
};
struct node{
    ll l,r;
    ll len;
    bool operator<(const node&o)const{
        return l>o.l;
    }
};
struct Q{
    ll l,r;
    int id;
    bool operator<(const Q&o){
        return l>o.l;
    }
};
void sol() {
    int n,q;cin>>n>>q;
    BIT bit((n+q)*4+5);
    vector<node> a(n);
    vector<ll> tmp,ans(q);
    vector<Q> b(q);
    for(int i=0;i<n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].len=a[i].r-a[i].l+1;
        tmp.push_back(a[i].l);
        tmp.push_back(a[i].r);
    } 
    for(int i=0;i<q;i++){
        cin>>b[i].l>>b[i].r;
        tmp.push_back(b[i].l);
        tmp.push_back(b[i].r);
        b[i].id=i;
    }
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    for(int i=0;i<n;i++){
        a[i].l=lower_bound(tmp.begin(),tmp.end(),a[i].l)-tmp.begin()+1;
        a[i].r=lower_bound(tmp.begin(),tmp.end(),a[i].r)-tmp.begin()+1;
        // cout<<a[i].l<<" "<<a[i].r<<'\n';
    }
    for(int i=0;i<q;i++){
        b[i].l=lower_bound(tmp.begin(),tmp.end(),b[i].l)-tmp.begin()+1;
        b[i].r=lower_bound(tmp.begin(),tmp.end(),b[i].r)-tmp.begin()+1;
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int idx=-1;
    for(int i=0;i<q;i++){
        while(idx+1<n&&a[idx+1].l>=b[i].l){
            idx++;
            bit.add(a[idx].r,a[idx].len);
        }
        ans[b[i].id]=bit.query(b[i].r);
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<'\n';
    }

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