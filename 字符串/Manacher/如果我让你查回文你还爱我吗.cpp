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
const int N=4e5+10;
struct Query{
    int l,r,id;
}Q[N>>1];
int R[N];
ll pp[N],ord[N],ans[N>>1],lc[N],rc[N];
int n,q;
void Manacher(const string&t){
    //R记录i位置的最长回文半径（不含自己），r是回文串最右侧再+1，最后的len是最长回文半径（不含自己）+1，每次通过取min更新len的时候，r-i的len是已知最长合法+1，R和0都是已知最长合法(不含自己)

    //模板中的R是在原串当中的最长回文直径
    string s="#";
    for(auto c:t) s+=c,s+='#';
    int n=s.size();
    for(int i=0,r=0,len,c;i<n;i++){
        len=i<r?min(r-i,R[c*2-i]):0;
        while(i-len>=0&&i+len<n&&s[i-len]==s[i+len]) len++;
        R[i]=len-1;
        if(i+len>r){
            r=i+len;
            c=i;
        }
    }
}
void sol() {
    string s;cin>>n>>q;
    cin>>s;
    Manacher(s);
    for(int i=1;i<2*s.size();i++){
        lc[i]=i-R[i]+1,rc[i]=i+R[i]-1;
        ord[i]=i;
        pp[i]=pp[i-1]+(R[i]/2)+(i&1);
    }
    int siz=2*s.size()+1;
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        l--,r--;
        Q[i]={2*l+1,2*r+1,i};
    }
    sort(ord+1,ord+siz-1,[&](int x,int y)->bool{
        return lc[x]<lc[y];
    });
    sort(Q,Q+q,[&](const Query&a,const Query&b)->bool{
        return a.l<b.l;
    });
    //b1维护某个位置的Lc,b2是个数
    BIT b1(siz+4),b2(siz+4);
    int pos=1;
    for(int i=0;i<q;i++){
        const auto[L,R,id]=Q[i];
        int mid=(L+R)>>1;
        while(pos<=siz-2&&lc[ord[pos]]<=L){
            int c=ord[pos];
            b1.rangeAdd(c,c,lc[ord[pos++]]);
            b2.rangeAdd(c,c,1);
        }
        ans[id]+=(pp[mid]-pp[L-1]+(b1.rangeQuery(L,mid)-L*b2.rangeQuery(L,mid))/2);
    }
    b1.init(siz+4),b2.init(siz+4);
    sort(ord+1,ord+siz-1,[&](int x,int y)->bool{
        return rc[x]<rc[y];
    });
    sort(Q,Q+q,[&](const Query&a,const Query&b)->bool{
        return a.r>b.r;
    });
    pos=siz-2;
    for(int i=0;i<q;i++){
        const auto[L,R,id]=Q[i];
        int mid=(L+R)>>1;
        if(mid+1<=R){
            while(pos>0&&rc[ord[pos]]>=R){  
                int c=ord[pos];
                b1.rangeAdd(c,c,rc[ord[pos--]]);
                b2.rangeAdd(c,c,1);
            }
            ans[id]+=(pp[R]-pp[mid]-(b1.rangeQuery(mid+1,R)-R*b2.rangeQuery(mid+1,R))/2);
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