#include <bits/stdc++.h>
using namespace std;

vector<long long> cost;
vector<vector<int>> roads;


void sol(){
    long long ans=0;
    int n=cost.size(),m=roads.size(),idx=0;
    
    vector<vector<int>> e(n);
    vector<int> dfn(n,0),low(n,0);
    stack<int> stk;
    vector<vector<int>> bcc;
    vector<bool> flag(n,false);
    for(int i=0;i<m;i++){
        int u=roads[i][0],v=roads[i][1];
        e[u].push_back(v),e[v].push_back(u);
    }
    auto Tarjan=[&](auto&&self,int u,int fa)->void{
        dfn[u]=low[u]=++idx;
        stk.push(u);
        int child=0;
        for(int v:e[u]){
            if(!dfn[v]){
                child++;
                self(self,v,u);
                low[u]=min(low[u],low[v]);
                if(low[v]>=dfn[u]){
                    if(fa^u) flag[u]=true;
                    vector<int> res;
                    res.push_back(u);
                    int x;
                    do{
                        x=stk.top();
                        res.push_back(x);
                        stk.pop();
                    }while(x^v);
                    bcc.push_back(res);
                }
            }else{
                low[u]=min(low[u],dfn[v]);
            }
        }
        if(fa==u&&child>=2) flag[u]=true;
    };
    Tarjan(Tarjan,0,0);
    if(bcc.size()==1){
        cout<<*min_element(cost.begin(),cost.end())<<'\n';
        return ;
    }else if(n==1){
        cout<<cost[0]<<'\n';
    }
    long long sum=0;
    for(auto &block:bcc){
        long long res=1e18;
        int number=0;
        for(int x:block){
            if(!flag[x]) res=min(res,cost[x]);
            else number++;
        }
        if(number==1){
            sum+=res;
            ans=max(res,ans);
        }
    }
    ans=sum-ans;
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    cost.resize(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        roads.push_back({u,v});
    }
    sol();
    return 0;
}