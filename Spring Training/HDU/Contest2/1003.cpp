#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

    反过来想，非常秒啊
    2026.04.03 1:17:01

*/
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define double long double
#define i128 __int128_t
#define ull unsigned long long  
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)

const int N=2e5+10;
int a[N],n;

struct node{
    int v=0,idx;
    node(){}
    node (int v_,int idx_):v(v_),idx(idx_){

    }
    bool operator<(const node&other)const{
        if(v==other.v) return idx<other.idx;
        return v<other.v;
    }
}mx[N<<2];

void up(int u){
    mx[u]=max(mx[ls],mx[rs]);
}

void build(int u,int l,int r){
    if(l==r){
        mx[u].v=a[l];
        mx[u].idx=l;
    }else{
        build(ls,l,mid);
        build(rs,mid+1,r);
        up(u);
    }
}

void add(int u,int ji,int jv,int l,int r){
    if(l==r){
        mx[u].v+=jv;
        return ;
    }
    if(ji<=mid) add(ls,ji,jv,l,mid);
    else add(rs,ji,jv,mid+1,r);
    up(u);
}

node query(int u,int jl,int jr,int l,int r){
    if(jl<=l&&r<=jr) return mx[u];
    node ans(-1,0);
    if(jl<=mid) ans=max(ans,query(ls,jl,jr,l,mid));
    if(jr>=mid+1) ans=max(ans,query(rs,jl,jr,mid+1,r));
    return ans;
}

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int x=1;x<n;x++){
        ll ans=0;
        int k=n/(x+1)+(n%(x+1)!=0);
        // cout<<'\n'<<x<<" "<<k<<'\n';
        vector<node> res;
        for(int i=1;i<=k;i++){
            node tmp=query(1,(k-i)*(x+1)+1,n,1,n);
            add(1,tmp.idx,-tmp.v,1,n);
            // cout<<tmp.v<<' ';
            ans+=(ll)tmp.v;
            res.push_back(tmp);
        }
        cout<<ans<<' ';
        for(auto&[val,x]:res){
            add(1,x,val,1,n);
        }
    }
    cout<<'\n';
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