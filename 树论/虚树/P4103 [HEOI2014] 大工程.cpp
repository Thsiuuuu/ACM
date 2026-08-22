#include <bits/stdc++.h>
using namespace std;

const int N=1e6+2;
#define ll long long 

ll dep[N],dfn[N],idx,st[N][21],siz[N],Mx[N],Mn[N];
vector<int> e[N],vt[N];
int stk[N],top;
bool is[N];
ll ans1=0,ans2=1e18,ans3=0;

void build(int u,int fa,ll &idx){
    dep[u]=dep[fa]+1,dfn[u]=++idx,st[u][0]=fa;
    for(int i=1;i<=20;i++){
        st[u][i]=st[st[u][i-1]][i-1];
    }
    for(int v:e[u]){
        if(fa^v){
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
        if(st[u][i]^st[v][i]){
            u=st[u][i],v=st[v][i];
        }
    }
    return st[u][0];
}

void dfs(int u,ll &tot){
    if(is[u])   siz[u]=1;
    ll s1,s2,b1,b2;
    s1=s2=1e18,b1=b2=0;
    for(int v:vt[u]){
        dfs(v,tot);
        siz[u]+=siz[v];
        ans1+=(dep[v]-dep[u])*siz[v]*(tot-siz[v]);
        ll d=dep[v]-dep[u];
        if(Mn[v]+d<s1) s2=min(s1,s2),s1=Mn[v]+d;
        else if(Mn[v]+d<s2) s2=Mn[v]+d;
        if(Mx[v]+d>b1) b2=max(b1,b2),b1=Mx[v]+d;
        else if(Mx[v]+d>b2) b2=Mx[v]+d;
    }
    // cout<<u<<" "<<b1<<" "<<b2<<'\n';
    if(is[u]){
        Mn[u]=0,Mx[u]=b1;
        ans2=min(ans2,s1),ans3=max(ans3,b1+b2); 
    }else ans2=min(ans2,s1+s2),ans3=max(ans3,(b1*b2)?b1+b2:0ll),Mn[u]=s1,Mx[u]=b1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    build(1,0,idx);
    for(int i=1;i<=n;i++) Mn[i]=1e18;
    int q;
    cin>>q;
    while(q--){
        ll k;cin>>k;
        ll ans=0;
        vector<int> p(k);
        for(int i=0;i<k;i++){
            cin>>p[i];is[p[i]]=true;
        }
        if(!is[1]) p.push_back(1);
        sort(p.begin(),p.end(),[&](int x,int y)->bool{
            return dfn[x]<dfn[y];
        });
        stk[++top]=p[0];
        int all=p.size();
        for(int i=1;i<all;i++){
            int lca=LCA(stk[top],p[i]);
            while(top>=2&&dep[stk[top-1]]>=dep[lca]){
                vt[stk[top-1]].push_back(stk[top]);
                top--;
            }
            if(lca^stk[top]){
                vt[lca].push_back(stk[top]);stk[top]=lca;p.push_back(lca);
            }
            stk[++top]=p[i];
        }
        while(top){
            vt[stk[top-1]].push_back(stk[top]); top--;
        }
        dfs(1,k);
        cout<<ans1<<" "<<ans2<<" "<<ans3<<'\n';
        for(auto x:p){
            Mn[x]=1e18,Mx[x]=0;
            vt[x].clear();
            is[x]=false,siz[x]=0;
        }
        ans1=ans3=0,ans2=1e18;
    }

    return 0;
}