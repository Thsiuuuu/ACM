#include <bits/stdc++.h>
using namespace std;

int n,m,k,q;

const int N=5e5+10,K=52;
int p[K][N<<1],siz[K][N<<1];
int a[N],b[N];
int e[N],c[N],post[N];//第i个时间染的边，边的颜色
bool ans[N];
int lastColor[N];

#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)


struct Edge{
    int color;
    int u,v;
};

stack<Edge> stk;
vector<int> edge[N<<2];


int find(int color,int x){
    while(x^p[color][x]){
        x=p[color][x];
    }
    return x;
    // return x==p[color][x]?x:find(color,p[color][x]);
}

void unite(int color,int x,int y){
    int fx=find(color,x),fy=find(color,y);
    if(fx^fy){
        if(siz[color][fx]<siz[color][fy]) swap(fx,fy);
        siz[color][fx]+=siz[color][fy];
        p[color][fy]=fx;
        stk.push({color,fx,fy});
    }
}

void add(int u,int l,int r,int jl,int jr,int i){
    if(jl>jr||jr<l||jl>r) return ;
    if(jl<=l&&r<=jr) return edge[u].push_back(i);
    add(ls,l,mid,jl,jr,i);
    add(rs,mid+1,r,jl,jr,i);
}

void solve(int u,int l,int r){
    int now=stk.size();
    for(int i:edge[u]){
        int x=a[e[i]],y=b[e[i]],color=c[i];
        int xn=x+n,yn=y+n;
        int fx=find(color,x),fy=find(color,y),fxn=find(color,xn),fyn=find(color,yn);
        if(fx^fyn){
            unite(color,fx,fyn);
            unite(color,fy,fxn);
        }
        // if(fy^fxn){
        // }
    }
    if(l==r){
        if(find(c[l],a[e[l]])==find(c[l],b[e[l]])){
            ans[l]=false;
            c[l]=lastColor[e[l]];
        }else{
            ans[l]=true;
            lastColor[e[l]]=c[l];
        }
    }else{
        solve(ls,l,mid);
        solve(rs,mid+1,r);
    }
    while(stk.size()>now){
        auto [color,x,y]=stk.top();
        stk.pop();
        p[color][y]=y;
        siz[color][x]-=siz[color][y];
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m>>k>>q;
    for(int i=1;i<=n;i++){
        for(int color=1;color<=k;color++){
            siz[color][i]=siz[color][i+n]=1;
            p[color][i]=i,p[color][i+n]=i+n;
        }
    }
    for(int i=1;i<=m;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=q;i++){
        cin>>e[i]>>c[i];
    }
    
    for(int i=1;i<=m;i++) post[i]=q;
    for(int i=q;i>=1;i--){
        if(i+1<=post[e[i]]){
            add(1,1,q,i+1,post[e[i]],i);
        }
        post[e[i]]=i;
    }

    solve(1,1,q);
    for(int i=1;i<=q;i++){
        cout<<(ans[i]?"YES":"NO")<<'\n';
    }
    return 0;
}