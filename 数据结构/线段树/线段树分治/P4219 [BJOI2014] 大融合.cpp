#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int n,q;
const int N=1e5+10;
int p[N];
ll siz[N],ans[N];
int a[N],b[N];
bool is[N];

#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs ((u<<1)|1)


struct edge{
    int u,v;
    bool operator<(const edge&other)const{
        if(u==other.u) return v<other.v;
        return u<other.u;
    }
};
stack<edge> stk;
vector<edge> tr[N<<2];
map<edge,int> mp;

int find(int i){
    return p[i]==i?i:find(p[i]);
}

void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx^fy){
        if(siz[fx]<siz[fy]) swap(fx,fy);
        siz[fx]+=siz[fy];
        p[fy]=fx;
        stk.push({fx,fy});
    }
}


void add(int u,int l,int r,int jl,int jr,const edge& i){
    if(jl>jr||jr<l||jl>r) return ;
    if(jl<=l&&r<=jr) return tr[u].push_back(i);
    add(ls,l,mid,jl,jr,i);
    add(rs,mid+1,r,jl,jr,i);
}

void solve(int u,int l,int r){
    int now=stk.size();
    for(auto [x,y]:tr[u]){
        unite(x,y);
    }
    if(l==r){
        if(is[l]){
            ans[l]=siz[find(a[l])]*siz[find(b[l])];
        }
    }else{
        solve(ls,l,mid);
        solve(rs,mid+1,r);
    }
    while(stk.size()>now){
        auto [x,y]=stk.top();stk.pop();
        siz[x]-=siz[y];
        p[y]=y;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++) siz[i]=1,p[i]=i;
    for(int i=1;i<=q;i++){
        char c;
        int u,v;
        cin>>c>>u>>v;
        a[i]=min(u,v),b[i]=max(u,v);
        if(c=='A'){
            mp.insert({edge{a[i],b[i]},i});
        }else{
            is[i]=true;
            auto it=mp.find(edge{a[i],b[i]});
            add(1,1,q,it->second,i-1,edge{a[i],b[i]});
            it->second=i+1;
        }
    }
    for(auto [key,val]:mp){
        if(val<=q) add(1,1,q,val,q,edge{key.u,key.v});
    }

    solve(1,1,q);
    for(int i=1;i<=q;i++){
        if(ans[i]){
            cout<<ans[i]<<'\n';
        }
    }
    return 0;
}