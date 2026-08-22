#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

const int N=2e4+10;
vector<int> e[N],ne[N<<1];
int idx,cnt,low[N],dfn[N],dep[N<<1],st[N<<1][21];
stack<int> stk;
int n,m;

void Tarjan(int u,int fa){
    dfn[u]=low[u]=++idx;
    stk.push(u);
    for(int v:e[u]){
        if(!dfn[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<=low[v]){
                int x;
                cnt++;
                do{
                    x=stk.top();
                    stk.pop();
                    ne[cnt].push_back(x),ne[x].push_back(cnt);
                }while(x^v);
                ne[u].push_back(cnt),ne[cnt].push_back(u);
            }
        }else low[u]=min(low[u],dfn[v]);
    }
}

void dfs1(int u,int fa){
    dep[u]=dep[fa]+1;
    st[u][0]=fa;
    for(int i=1;i<=20;i++){
        st[u][i]=st[st[u][i-1]][i-1];
    }
    for(int v:ne[u]){
        if(v^fa){
            dfs1(v,u);
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

int dis(int u,int v){
    return (dep[u]+dep[v]-2*dep[LCA(u,v)]);
}

void sol() {
    cin>>n>>m;
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    cnt=n;
    Tarjan(1,1);
    dfs1(1,0);
    int q;
    cin>>q;
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        if(dis(a,b)==dis(a,c)+dis(b,c)) cout<<"yes\n";
        else cout<<"no\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}