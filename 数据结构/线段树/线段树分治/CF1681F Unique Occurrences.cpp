#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int N=5e5+10;
int p[N],siz[N];

#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)

struct Edge{
    int x,y;
};
stack<Edge> stk;
ll ans=0,n;
int a[N],b[N],w[N];
vector<int> tr[N<<2];
vector<Edge> e[N];//每个权值的所有边

int find(int x){
    return p[x]==x?x:find(p[x]);
}

void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx^fy){
        if(siz[fy]>siz[fx]) swap(fx,fy);
        siz[fx]+=siz[fy];
        p[fy]=fx;
        stk.push({fx,fy});
    }
}

void insert(int u,int l,int r,int jl,int jr,int i){
    if(l>jr||r<jl) return ;
    if(jl<=l&&r<=jr) return tr[u].push_back(i);
    insert(ls,l,mid,jl,jr,i);
    insert(rs,mid+1,r,jl,jr,i);
}

void solve(int u,int l,int r){
    int now=stk.size();
    for(int i:tr[u]){
        unite(a[i],b[i]);
    }
    if(l==r){
        for(auto [x,y]:e[l]){
            int fx=find(x),fy=find(y);
            ans+=1ll*siz[fx]*siz[fy];
        }
    }else{
        solve(ls,l,mid);
        solve(rs,mid+1,r);
    }
    while(stk.size()>now){
        auto [x,y]=stk.top();
        stk.pop();
        siz[x]-=siz[y];
        p[y]=y;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++) p[i]=i,siz[i]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>w[i];
        e[w[i]].push_back({a[i],b[i]});
        insert(1,1,n,1,w[i]-1,i);
        insert(1,1,n,w[i]+1,n,i);
    }
    solve(1,1,n);
    cout<<ans;
    return 0;
}