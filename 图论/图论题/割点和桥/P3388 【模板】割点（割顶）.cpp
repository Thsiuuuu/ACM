#include <bits/stdc++.h>
using namespace std;

int n,m;
const int N=1e5+10;
int dfn[N],low[N],idx,res;
bool vis[N],flag[N];
vector<int> e[N];

void Tarjan(int u,int fa){
    vis[u]=true;
    low[u]=dfn[u]=++idx;
    int child=0;
    for(int v:e[u]){
        if(!vis[v]){
            child++;
            Tarjan(v,u);
            low[u]=min(low[v],low[u]);
            if(fa!=u&&low[v]>=dfn[u]&&!flag[u]){
                flag[u]=true;
                res++;
            }
        }else if(v^fa){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(fa==u&&child>=2&&!flag[u]){
        flag[u]=true;
        res++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            idx=0;
            Tarjan(i,i);
        }
    }
    cout<<res<<'\n';
    for(int i=1;i<=n;i++){
        if(flag[i]) cout<<i<<" ";
    }
    return 0;
}