#include <bits/stdc++.h>
using namespace std;

const int N=1e3+5;

int mp[N][N];
int n,m;

int dfn[N],low[N],idx;
vector<vector<int>> bcc;
stack<int> stk;
bool flag[N],vis[N],is[N];
int number[N];

void Tarjan(int u,int fa){
    dfn[u]=low[u]=++idx;
    stk.push(u);
    for(int v=1;v<=n;v++){
        if(!mp[u][v]||v==fa) continue; 
        if(!dfn[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                int x;
                vector<int> res;
                res.push_back(u);
                do{
                    x=stk.top();stk.pop();
                    res.push_back(x);
                }while(x^v);
                bcc.push_back(res);
            }
        }else low[u]=min(low[u],dfn[v]);
    }
}

void sol(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mp[i][j]=0;
        }
        flag[i]=vis[i]=is[i]=false;
        dfn[i]=low[i]=number[i]=0;
    }
    idx=0;
    if(bcc.size()) bcc.clear();
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        mp[u][v]=mp[v][u]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) mp[i][j]=0;
            else mp[i][j]^=1;
        }
    }

    for(int i=1;i<=n;i++){
        if(!dfn[i]) Tarjan(i,i);
    }


    auto dfs=[&](auto &&self,int u,int x,int cnt)->bool{
        vis[u]=1;
        number[u]=x;
        for(int v:bcc[cnt]){
            if(mp[u][v]==0) continue;
            if(vis[v]){
                if(number[v]==x) return false;    
            }else if(!self(self,v,x^1,cnt)) return false;
        }
        return true;
    };

    // for(int i=0;i<bcc.size();i++){
    //     cout<<i<<'\n';
    //     for(int j=0;j<bcc[i].size();j++){
    //         cout<<bcc[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }

    int ans=0;
    for(int i=0;i<bcc.size();i++){
        bool f=dfs(dfs,bcc[i][0],0,i);
        for(int j=0;j<bcc[i].size();j++){
            if(!f)   is[bcc[i][j]]=true;
            vis[bcc[i][j]]=false;
        }
        
    }
    for(int i=1;i<=n;i++) if(!is[i]) ans++; 
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    while(1){
        cin>>n>>m;
        if((n|m)==0) return 0;
        sol();
    }
}