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
    bool operator<(const Event&o) const {
        return x<o.x;
    }
};
const int N=1e5+10;
struct node{
    int cnt=0;
    ll len=0;
}tr[N<<3];
VL Y;
void pushup(int u,int l,int r){
    if(tr[u].cnt>0) tr[u].len=Y[r]-Y[l-1];
    else if(l==r) tr[u].len=0;
    else tr[u].len=tr[ls].len+tr[rs].len;
}
void update(int u,int l,int r,int jl,int jr,int jv){
    if(jl<=l&&r<=jr){
        tr[u].cnt+=jv;
        pushup(u,l,r);
        return ;
    }
    if(jl<=mid) update(ls,l,mid,jl,jr,jv);
    if(jr>mid) update(rs,mid+1,r,jl,jr,jv);
    pushup(u,l,r);
}
void sol() {
    int n;cin>>n;
    vector<Event> events;
    for(int i=0;i<n;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        events.push_back({a,b,d,+1});
        events.push_back({c,b,d,-1});
        Y.push_back(b);
        Y.push_back(d);
    }
    sort(Y.begin(),Y.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    sort(events.begin(),events.end());
    ll ans=0;
    ll lastx=events[0].x;
    int m=Y.size();
    for(const auto&[x,y1,y2,op]:events){
        ans+=(x-lastx)*tr[1].len;
        int l=lower_bound(Y.begin(),Y.end(),y1)-Y.begin()+1;
        int r=lower_bound(Y.begin(),Y.end(),y2)-Y.begin();
        update(1,1,m-1,l,r,op);
        lastx=x;
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