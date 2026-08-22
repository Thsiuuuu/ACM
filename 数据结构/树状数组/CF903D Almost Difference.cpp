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
void print(i128 x){
    if(x==0){
        cout<<"0\n";
        return ;
    }
    if(x<0){
        cout<<"-";
        x=-x;
    }
    string s;
    while(x){
        s+=char('0'+x%10);
        x/=10;
    }
    reverse(s.begin(),s.end());
    cout<<s<<'\n';
}
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
            a[i] += v;
            b[i] += 1LL * p * v;
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
            res += 1LL * (p + 1) * a[i] - b[i];
        }
        return res;
    }
    // 区间和
    ll rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};
void sol() {
    int n;cin>>n;
    VL a,b;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        a.push_back(x);
        b.push_back(x);
        b.push_back(x+1);
        b.push_back(x-1);
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    BIT b1(b.size()+1),b2(b.size()+1);
    i128 sum=0;
    ll Lim=b.size()+1;
    for(int i=n-1;i>=0;i--){
        int i1=lower_bound(b.begin(),b.end(),a[i]+1)-b.begin()+1,
            i2=lower_bound(b.begin(),b.end(),a[i]-1)-b.begin()+1,
            i3=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
        // cout<<a[i]<<' ';
        // cout<<i1<<" "<<i2<<" "<<i3<<'\n';
        // ll d1,d2;d1=d2=0;
        sum+=(a[i]*(b1.query(Lim)-b1.query(i1))-(b2.query(Lim)-b2.query(i1)));
        sum+=(a[i]*(b1.query(i2)-b1.rangeQuery(i2,i2))-(b2.query(i2)-b2.rangeQuery(i2,i2)));
        // cout<<d1<<' '<<d2<<'\n';
        b1.rangeAdd(i3,i3,1);
        b2.rangeAdd(i3,i3,a[i]);
    }
    // cout<<'\n';
    // print(sum);
    print(-sum);
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