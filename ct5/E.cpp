#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

#define int long long 

/*
    强连通分量缩点

*/


const int N=1e5+10;
int low[N],dfn[N],tot;
int stk[N],instk[N],cnt,top;
int siz[N],scc[N];
int number[N];
vector<int> e[N];

int cost[N];
int n,m;


void tarjan(int x){
    low[x]=dfn[x]=++tot;
    stk[++top]=x;
    instk[x]=1;
    for(int y:e[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[y],low[x]);
        }else if(instk[y]){
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(low[x]==dfn[x]){
        int y;cnt++;
        do{
            y=stk[top--];
            scc[y]=cnt;
            siz[scc[y]]++;
            instk[y]=0;
            number[scc[y]]=min(cost[y],number[scc[y]]);
            // cout<<number[scc[y]]<<"\n";
        }while(y!=x);
    }
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    for(int i=0;i<=n;i++) number[i]=INT_MAX;

    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    
    // for(int i=1;i<=n;i++) cout<<scc[i]<<" ";
    // cout<<"\n";
    int sum=0;
    for(int i=1;i<=cnt;i++){
        // cout<<number[i]<<" ";
        sum+=number[i];
    }
    cout<<sum;
    return 0;
}