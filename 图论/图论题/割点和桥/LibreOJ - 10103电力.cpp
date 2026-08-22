#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int n,m;
const int N=1e4+10;
int dfn[N],low[N],idx;
int ans=0;
vector<int> e[N];
bool vis[N];


void Tarjan(int u,int fa){
    vis[u]=true;
    low[u]=dfn[u]=++idx;
    int child=0;
    int res=0;
    for(int v:e[u]){
        if(!vis[v]){
            child++;
            Tarjan(v,u);
            low[u]=min(low[v],low[u]);
            if(fa!=u&&low[v]>=dfn[u]){
                res++;
            }
        }else if(v^fa){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(fa^u) ans=max(ans,res+1);
    else if(fa==u){
        ans=max(ans,child);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    while(cin>>n>>m){ 
        if(n==0&&m==0) return 0;
        for(int i=1;i<=n;i++){
            e[i].clear();
            vis[i]=false;
            dfn[i]=low[i]=0;
        }
        idx=0;
        ans=0;
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            u++,v++;
            e[u].push_back(v),e[v].push_back(u);
        }
        int number=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                number++;
                Tarjan(i,i);
            }
        }
        cout<<number-1+ans<<'\n';
    }
    return 0;
}