#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=3e5+2;

struct Edge{
    int v;
    ll w;
};

ll  st[N][21][2],f[N],dep[N],dfn[N],idx;//0点，1边权
vector<Edge> vt[N],e[N];
int stk[N],top;
bool is[N];

void build(int u,int fa,ll w,ll &idx){
    dep[u]=dep[fa]+1,st[u][0][0]=fa,st[u][0][1]=w;
    dfn[u]=++idx;
    for(int i=1;i<=20;i++){
        st[u][i][0]=st[st[u][i-1][0]][i-1][0];
        st[u][i][1]=min(st[u][i-1][1],st[st[u][i-1][0]][i-1][1]);
    }
    for(auto&[v,_]:e[u]){
        if(v!=fa&&v!=0){
            build(v,u,_,idx);
        }
    }
}

int LCA(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--){
        if(dep[st[x][i][0]]>=dep[y]) x=st[x][i][0];
    }
    if(x==y) return x;
    for(int i=20;i>=0;i--){
        if(st[x][i][0]!=st[y][i][0]){
            x=st[x][i][0],y=st[y][i][0];
        }
    }
    return st[x][0][0];
}

ll dis(int x,int y){
    ll w=1e18;
    // cout<<x<<" "<<y<<'\n';
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--){
        if(dep[st[x][i][0]]>=dep[y]){
            w=min(w,st[x][i][1]);
            x=st[x][i][0];
        }
    }
    return w;
}

void dfs(int u){
    for(auto [v,w]:vt[u]){
        // cout<<u<<" "<<v<<" "<<w<<'\n';
        dfs(v);
        if(is[v]){
            f[u]+=w;
        }else f[u]+=min(w,f[v]);
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w}),e[v].push_back({u,w});
    }
    build(1,0,1e18,idx);
    cin>>m;
    while(m--){
        int k;cin>>k;
        vector<int> p(k+1,1);
        for(int i=1;i<=k;i++){
            cin>>p[i];
            is[p[i]]=true;
        }
        sort(p.begin(),p.end(),[&](int u,int v)->bool{
            return dfn[u]<dfn[v];
        });
        stk[++top]=p[0];
        
        for(int i=1;i<=k;i++){
            int lca=LCA(stk[top],p[i]);
            while(top>=2&&dep[stk[top-1]]>=dep[lca]){
                vt[stk[top-1]].push_back({stk[top],dis(stk[top],stk[top-1])});
                top--;
            }
            if(lca^stk[top]){
                vt[lca].push_back({stk[top],dis(stk[top],lca)});stk[top]=lca;
                p.push_back(lca);
            }
            stk[++top]=p[i];
        }
        while(top){
            vt[stk[top-1]].push_back({stk[top],dis(stk[top],stk[top-1])});//不能直接--,函数参数求值顺序没有规定！
            top--;
        }
        dfs(1);
        cout<<f[1]<<'\n';
        for(int x:p){
            is[x]=false,f[x]=0;
            vt[x].clear();
        }
        top=0;
    }
    return 0;
}