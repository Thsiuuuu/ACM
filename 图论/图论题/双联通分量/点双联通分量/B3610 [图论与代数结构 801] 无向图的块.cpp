#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
vector<int> e[N];
vector<vector<int>> dcc;
int idx,low[N],dfn[N];
stack<int> stk;
int n,m;

void Tarjan(int u,int fa){
    dfn[u]=low[u]=++idx;
    stk.push(u);
    for(int v:e[u]){
        if(!dfn[v]){
            Tarjan(v,u);
            low[u]=min(low[v],low[u]);
            if(dfn[u]<=low[v]){
                vector<int> ans;
                int x;
                do{
                    x=stk.top();
                    ans.push_back(x);
                    stk.pop();
                }while(x^v);
                ans.push_back(u);
                dcc.push_back(ans);
            }
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(u^v){
            e[u].push_back(v),e[v].push_back(u);
        }   
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            if(e[i].size()) Tarjan(i,i);
        }
    }
    
    for(auto& ans:dcc) sort(ans.begin(),ans.end());
    sort(dcc.begin(),dcc.end());
    cout<<dcc.size()<<'\n';
    for(auto ans:dcc){
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<'\n';
    }
    return 0;
}