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
const ll P=1000000007;
int n,m;
ll seed,vmax;
ll ksm(ll a,ll b,ll mod){
    a=a%mod;
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
struct Node_t{
    int l,r;
    mutable ll v;
    Node_t (const int &il,const int &ir,const ll &iv):l(il),r(ir),v(iv){}
    bool operator<(const Node_t&o)const{
        return l<o.l;
    }
};
set<Node_t> odt;
auto split(int x){
    auto it=odt.lower_bound(Node_t(x,0,0));
    if(it!=odt.end()&&it->l==x) return it;
    --it;
    int l=it->l,r=it->r;
    ll v=it->v;
    odt.erase(it);
    odt.insert(Node_t(l,x-1,v));
    return odt.insert(Node_t(x,r,v)).first;
    //insert返回<插入位置的迭代器,是否插入成功>
}
void assign(int l,int r,ll v){
    auto itr=split(r+1),itl=split(l);
    odt.erase(itl,itr);
    odt.insert(Node_t(l,r,v));
}
void add(int l,int r,ll val){
    auto itr=split(r+1),itl=split(l);
    for(;itl!=itr;itl++) itl->v+=val;
}
ll ranks(int l,int r,int k){
    vector<pll> vp;
    auto itr=split(r+1),itl=split(l);
    for(;itl!=itr;itl++) vp.push_back(make_pair(itl->v,itl->r-itl->l+1));
    sort(vp.begin(),vp.end());
    for(auto it=vp.begin();it!=vp.end();it++){
        k-=it->second;//减去数的个数
        if(k<=0) return it->first;
    }
}
ll sum(ll l,ll r,int ex,ll mod){
    auto itr=split(r+1),itl=split(l);
    ll res=0;
    for(;itl!=itr;itl++){
        res=(res+(ll)(itl->r-itl->l+1)*ksm(itl->v,ex,mod))%mod;
    }
    return res;
}
 
ll rnd(){
    ll res=seed;
    seed=(seed*7+13)%P;
    return res;
}
void sol() {
    cin>>n>>m>>seed>>vmax;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        a[i]=(rnd()%vmax)+1;
        odt.insert(Node_t(i,i,a[i]));
    }
    odt.insert(Node_t(n+1,n+1,0));
    for(int i=1;i<=m;i++){
        int op=(rnd()%4)+1;
        int l=(rnd()%n)+1,
            r=(rnd()%n)+1;
        if(l>r) swap(l,r);
        if(op==3){
            ll x=(rnd()%(r-l+1))+1;
            cout<<ranks(l,r,x)<<'\n';
        }else if(op==1){
            ll x=(rnd()%vmax)+1;
            add(l,r,x);
        }else if(op==2){
            ll x=(rnd()%vmax)+1;
            assign(l,r,x);
        }else{
            ll x=(rnd()%vmax)+1;
            ll y = (rnd() %vmax) + 1;
            cout<<sum(l,r,x,y)<<'\n';
        }
    }
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