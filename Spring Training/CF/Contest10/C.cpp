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
#define rs  ((u<<1)|1)
#define ls  (u<<1)
const int N=4e5+3;
// int cnt[N>>1];
int tg[N<<2],a[N>>1];
pii tr[N<<2];//第一维编号，第二维数量
int n,m;
void up(int u){
    if(tr[ls].second<tr[rs].second) tr[u]=tr[rs];
    else{
        tr[u]=tr[ls];
    }
    tr[u].second+=tg[u];
}
void build(int u,int l,int r){
    tg[u]=0;
    if(l==r){
        tr[u].first=l;
        tr[u].second=0;
    }else{
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        up(u);
    }
}
void RegionAdd(int u,int l,int r,int jl,int jr,int jv){
    if(l==r){
        tr[u].second+=jv;
        return ;
    }
    if(jl<=l&&r<=jr){
        tg[u]+=jv;
        tr[u].second+=jv;
        return ;
    }
    int mid=(l+r)>>1;
    if(jl<=mid){
        RegionAdd(ls,l,mid,jl,jr,jv);
    }
    if(jr>mid){
        RegionAdd(rs,mid+1,r,jl,jr,jv);
    }
    up(u);
}

pii Query(int u,int l,int r,int jl,int jr){
    if(l==r) return tr[u];
    if(jl<=l&&r<=jr) return tr[u];
    int mid=(l+r)>>1;
    pii tmp={11451419,-1};
    if(jl<=mid){
        tmp=Query(ls,l,mid,jl,jr);
    }
    if(jr>mid){
        auto R1=Query(rs,mid+1,r,jl,jr);
        if(tmp.second<R1.second) tmp=R1;
    }
    tmp.second+=tg[u];
    return tmp;
}
struct Node{
    int l,r;
    mutable int d;
    mutable int len;
    Node(const int &il,const int &ir,const int &id,const int &ilen):l(il),r(ir),d(id),len(ilen){}
    bool operator<(const Node&o)const{
        return l<o.l;
    }
};
set<Node> odt;
auto split(int x){
    auto it=odt.lower_bound(Node(x,0,0,0));
    if(it!=odt.end()&&it->l==x) return it;
    --it;
    int l=it->l,r=it->r,d=it->d,len=it->len;
    odt.erase(it);
    odt.insert(Node(l,x-1,d,x-l));
    return odt.insert(Node(x,r,d+x-l,r-x+1)).first;
}
void assign(int l,int r,int x,int len){
    auto itr=split(r+1),itl=split(l);
    auto it=itl;
    for(;it!=itr;it++){
        RegionAdd(1,1,2*n,it->d,it->d+it->len-1,-1);
    }
    odt.erase(itl,itr);
    it=odt.insert(Node(l,r,x,len)).first;
    RegionAdd(1,1,2*n,it->d,it->d+it->len-1,1);
}
void sol() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // cnt[a[i]]++;
    }
    odt.clear();
    build(1,1,2*n);
    // odt.insert(Node(1,n+1,0,0));
    for(int i=1;i<=n;i++){
        int j=i+1;
        while(j<=n&&a[j]==a[j-1]+1){
            j++;
        }
        odt.insert(Node(i,j-1,a[i],j-i));
        RegionAdd(1,1,2*n,a[i],a[i]+j-i-1,1);
        i=j-1;
    }    
    odt.insert(Node(n+1,n+1,0,1));
    auto tmp=Query(1,1,2*n,1,2*n);
    cout<<tmp.first<<" "<<tmp.second<<'\n';
    while(m--){
        int l,r,d;
        cin>>l>>r>>d;
        assign(l,r,d,r-l+1);
        tmp=Query(1,1,2*n,1,2*n);
        cout<<tmp.first<<" "<<tmp.second<<'\n';
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