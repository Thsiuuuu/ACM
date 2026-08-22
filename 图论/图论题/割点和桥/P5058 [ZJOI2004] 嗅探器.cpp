#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int dfn[N],low[N],idx;
int n,a,b;
vector<int> e[N];
bool flag[N];

void Tarjan(int u,int fa){
    dfn[u]=low[u]=++idx;
    for(int v:e[u]){
        if(!dfn[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(u!=fa&&low[v]>=dfn[u]&&!flag[u]&&dfn[v]<=dfn[b]){
                flag[u]=true;
            }
        }else if(v^fa){
            low[u]=min(low[u],dfn[v]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    while(1){
        int u,v;
        cin>>u>>v;
        if(u==0&&v==0) break;
        else{
            e[u].push_back(v),e[v].push_back(u);
        }
    }
    cin>>a>>b;
    Tarjan(a,a);    
    for(int i=1;i<=n;i++){
        if(flag[i]){
            cout<<i;
            return 0;
        }
    }
    cout<<"No solution";
    return 0;
}