#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int dep[N],st[N][21],dfn[N],stk[N],top,f[N];
int idx;
vector<int> e[N],vt[N];
bool g[N],is[N];

void build(int u,int fa,int& idx){
    dep[u]=dep[fa]+1;
    st[u][0]=fa;
    dfn[u]=++idx;
    for(int i=1;i<=20;i++){
        st[u][i]=st[st[u][i-1]][i-1];
    }
    for(int v:e[u]){
        if(v^fa){
            build(v,u,idx);
        }
    }
}

int LCA(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=20;i>=0;i--){
        if(dep[st[u][i]]>=dep[v]) u=st[u][i];
    }
    if(u==v) return u;
    for(int i=20;i>=0;i--){
        if(st[u][i]^st[v][i]) u=st[u][i],v=st[v][i];
    }
    return st[u][0];
}

void dfs(int u,bool &yes){
    int tot=0;
    for(int v:vt[u]){
        dfs(v,yes);
        if(is[u]&&is[v]&&(st[u][0]==v||st[v][0]==u)){
            yes=true;
            return ;
        }
        if(g[v]) tot++;
        f[u]+=f[v];
    }
    if(is[u]){
        f[u]+=tot,g[u]=1;
    }else{
        if(tot==1)  g[u]=1;
        else if(tot>1) f[u]+=1;
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,q;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    build(1,0,idx);
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        vector<int> p(k+1);   
        bool yes=false;
        for(int i=0;i<k;i++){
            cin>>p[i];
            is[p[i]]=true;
        }

        if(!is[1]) p.push_back(1);
        sort(p.begin(),p.end(),[&](int x,int y)->bool{
            return dfn[x]<dfn[y];
        });

        stk[++top]=p[0];
        int siz=p.size();
        for(int i=1;i<siz;i++){
            int lca=LCA(stk[top],p[i]);
            while(top>=2&&dep[stk[top-1]]>=dep[lca]){
                vt[stk[top-1]].push_back(stk[top--]);
            }
            if(lca^stk[top]){ vt[lca].push_back(stk[top]);  stk[top]=lca; p.push_back(lca);}
            stk[++top]=p[i];
        }
        while(top) vt[stk[top-1]].push_back(stk[top--]);
        dfs(1,yes);
        if(yes) cout<<"-1\n";
        else    cout<<f[1]<<'\n';
        for(int i=0;i<p.size();i++){
            g[p[i]]=is[p[i]]=false;
            f[p[i]]=0;
            vt[p[i]].clear();
        } 
        top=0;
    }
    return 0;
}