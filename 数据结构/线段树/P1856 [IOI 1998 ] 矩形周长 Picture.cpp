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
struct Event{
    int x,y1,y2;
    int op;
    bool operator<(const Event&o)const{
        if(x==o.x) return op>o.op;
        return x<o.x;
    }
};
const int N=5010;
struct node{
    /*
        cover整体被覆盖的次数
        len 被覆盖的总长度
        seg 被覆盖的连续段的段数
        lc,rc 区间最左和最右是否被覆盖
    */
    int cover,len,seg;
    bool lc,rc;
}tr[N<<3];
VI Y;
void pushup(int u,int l,int r){
    if(tr[u].cover>0){
        tr[u].len=Y[r]-Y[l-1];
        tr[u].seg=1;
        tr[u].lc=tr[u].rc=true;
    }else if(l==r){
        tr[u].len=0;
        tr[u].seg=0;
        tr[u].lc=tr[u].rc=false;
    }else{
        tr[u].len=tr[ls].len+tr[rs].len;
        tr[u].seg=tr[ls].seg+tr[rs].seg-(tr[ls].rc&&tr[rs].lc);
        tr[u].lc=tr[ls].lc;
        tr[u].rc=tr[rs].rc;
    }
}
void update(int u,int l,int r,int jl,int jr,int jv){
    if(jl<=l&&r<=jr) {
        tr[u].cover+=jv;
        pushup(u,l,r);
        return ;
    }
    if(jl<=mid) update(ls,l,mid,jl,jr,jv);
    if(jr>mid) update(rs,mid+1,r,jl,jr,jv);
    pushup(u,l,r);
}
void sol() {
    int n;cin>>n;
    vector<Event> event;
    for(int i=0;i<n;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        event.push_back({a,b,d,+1});
        event.push_back({c,b,d,-1});
        Y.push_back(b);
        Y.push_back(d);
    }
    sort(Y.begin(),Y.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    sort(event.begin(),event.end());
    int m=Y.size();
    ll ans=0;
    for(int i=0;i<event.size();i++){
        const auto&[x,y1,y2,op]=event[i];
        int l=lower_bound(Y.begin(),Y.end(),y1)-Y.begin()+1;
        int r=lower_bound(Y.begin(),Y.end(),y2)-Y.begin();
        ll oldlen=tr[1].len;
        update(1,1,m,l,r,op);
        ans+=abs(tr[1].len-oldlen);
        if(i+1<(int)event.size()){
            ll dx=event[i+1].x-x;
            ans+=2ll*tr[1].seg*dx;
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