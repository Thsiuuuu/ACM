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
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
const int N=1e4+10;
ll mx[N<<3],lazy[N<<3];
void pushup(int u){
    mx[u]=max(mx[ls],mx[rs]);
}
void build(int u,int l,int r){
    mx[u]=lazy[u]=0;
    if(l==r){
        return ;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void pushdown(int u){
    ll sum=lazy[u];
    lazy[u]=0;
    lazy[ls]+=sum,mx[ls]+=sum;
    lazy[rs]+=sum,mx[rs]+=sum;
}
void add(int u,int l,int r,int jl,int jr,int jv){
    if(jl<=l&&r<=jr){
        lazy[u]+=jv,mx[u]+=jv;
        return ;
    }
    pushdown(u);
    if(jl<=mid){
        add(ls,l,mid,jl,jr,jv);
    }
    if(jr>mid){
        add(rs,mid+1,r,jl,jr,jv);
    }
    pushup(u);
}
struct Event{
    ll x,y1,y2,op;
    bool operator<(const Event&o)const{
        return x<o.x;
    }
};
void sol() {
    ll n,w,h;cin>>n>>w>>h;
    VI Y;
    vector<Event> event;  
    for(int i=0;i<n;i++){
        int x,y,l;cin>>x>>y>>l;
        event.push_back({x,y,y+h,l});
        event.push_back({x+w,y,y+h,-l});
        Y.push_back(y);
        Y.push_back(y+h);
    }
    sort(Y.begin(),Y.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    sort(event.begin(),event.end());
    int m=Y.size();
    build(1,1,m);
    ll ans=0;
    for(int i=0;i<event.size();i++){
        int j=i;
        for(;j<event.size()&&event[j].x==event[i].x;j++){
            int l=lower_bound(Y.begin(),Y.end(),event[j].y1)-Y.begin()+1;
            int r=lower_bound(Y.begin(),Y.end(),event[j].y2)-Y.begin();
            add(1,1,m,l,r,event[j].op);
        }
        i=j-1;
        ans=max(ans,mx[1]);
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