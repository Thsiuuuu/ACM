#include <bits/stdc++.h>
using namespace std;


#define mid ((l+r)>>1)
#define ls u<<1
#define rs u<<1|1
const int N=1e5+10;
int n,k,m;
int a[N<<1],b[N<<1];
int p[N],siz[N];

struct Edge{
    int x,y;
};
stack<Edge> stk;
vector<int> tr[N<<2];

int find(int x){
    return p[x]==x?x:find(p[x]);
}

void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx^fy){
        if(siz[fx]<siz[fy]) swap(fx,fy);
        stk.push({fx,fy});
        p[fy]=fx;
        siz[fx]+=siz[fy];
    }
}

void insert(int u,int l,int r,int jl,int jr,int i){
    if(jl>jr) return;
    if(jr<l||jl>r) return;
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
        // cout<<siz[find(1)]<<'\n';
        if(siz[find(1)]==n){
            cout<<"Connected\n";
        }else{
            cout<<"Disconnected\n";
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

    cin>>n>>m;
    vector<int> last(m+1,1);
    for(int i=1;i<=n;i++) p[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        for(int j=1;j<=c;j++){
            int idx;
            cin>>idx;
            insert(1,1,k,last[idx],i-1,idx);
            last[idx]=i+1;
        }
    }
    for(int i=1;i<=m;i++){
        if(last[i]<=k){
            insert(1,1,k,last[i],k,i);
        }
    }
    solve(1,1,k);
    return 0;
}