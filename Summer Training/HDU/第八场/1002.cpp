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
struct BIT{
    int n;
    vector<ull> a,b;
    BIT(int n=0){
        init(n);
    }
    void init(int n_){
        n=n_;
        a.assign(n+2,0);
        b.assign(n+2,0);
    }
    void add(int p,ull v){
        for(int i=p;i<=n;i+=i&-i){
            a[i]+=v;
            b[i]+=1ull*p*v;
        }
    }
    void rangeAdd(int l,int r,ull v){
        add(l,v);
        add(r+1,-v);
    }
    ull query(int p){
        ull res=0;
        for(int i=p;i;i-=i&-i){
            res+=1ull*(p+1)*a[i]-b[i];
        }
        return res;
    }
    ull rangeQuery(int l,int r){
        return query(r)-query(l-1);
    }
};
void sol() {
    int n;ull m;cin>>n>>m;
    BIT b1(n+2),b2(n+2);
    for(int i=1;i<=n;i++){
        ull x;
        cin>>x;
        b1.rangeAdd(i,i,x);
        cin>>x;
        b1.rangeAdd(i,i,m*x);
        b2.rangeAdd(i,i,x);
    }
    for(int k=1;k<=m;k++){
        int op,l,r;cin>>op>>l>>r;
        if(op==1){
            ull x;cin>>x;
            b1.rangeAdd(l,r,(m-k)*x);
            b2.rangeAdd(l,r,x);
        }else{
            cout<<b1.rangeQuery(l,r)-(m-k)*b2.rangeQuery(l,r)<<'\n';
        }
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