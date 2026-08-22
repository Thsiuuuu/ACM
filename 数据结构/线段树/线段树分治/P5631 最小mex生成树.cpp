#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v;
};
stack<Edge> stk;
const int N=2e6+10;
int p[N],siz[N];
int a[N],b[N],w[N];
int n,m,mx;

vector<int> tr[N<<1];

int find(int x){
    return p[x]==x?x:find(p[x]);
}

void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return ;
    if(siz[fx]<siz[fy]) swap(fx,fy);
    siz[fx]+=siz[fy];
    stk.push({fx,fy});
    p[fy]=fx;
}

void insert(int u,int l,int r,int jl,int jr,int i){
    if(l>jr||r<jl) return ;
    if(jl<=l&&r<=jr){
        tr[u].push_back(i);
        return ;
    }
    int mid=(l+r)>>1;
    insert(u<<1,l,mid,jl,jr,i);
    insert(u<<1|1,mid+1,r,jl,jr,i);
}

void solve(int u,int l,int r){
    int now=stk.size();
    for(auto i:tr[u]) unite(a[i],b[i]);
    if(l==r){
        if(siz[find(1)]==n){
            cout<<l;
            exit(0);
        }
    }else{
        int mid=(l+r)>>1;
        solve(u<<1,l,mid);
        solve(u<<1|1,mid+1,r);
    }

    while(stk.size()>now){
        auto [x,y]=stk.top();
        stk.pop();
        p[y]=y;
        siz[x]-=siz[y];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>w[i];
        mx=max(mx,w[i]+1);
    }
    for(int i=1;i<=m;i++){
        insert(1,0,mx,0,w[i]-1,i);
        insert(1,0,mx,w[i]+1,mx,i);
    }
    solve(1,0,mx);
    return 0;
}