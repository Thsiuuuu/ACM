#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int tim=1;
void dfs(int u,vector<vector<int>>& adj,vector<int>&d,vector<int>&f,vector<bool>& visited){

    d[u]=tim++;
    visited[u]=true;

    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v,adj,d,f,visited);
        }
    }

    f[u]=tim++;
}


int main(){
    int n;
    cin>>n;

    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;i++){
        int u,k;
        cin>>u>>k;
        adj[u].resize(k);
        for(int j=0;j<k;j++) cin>>adj[u][j];


        sort(adj[u].begin(),adj[u].end());
    }


    vector<int> d(n+1,0);
    vector<int> f(n+1,0);

    vector<bool> visited(n+1,false);

    for(int u=1;u<=n;u++){
        if(!visited[u])
            dfs(u,adj,d,f,visited);
    }

    for(int u=1;u<=n;u++)
        cout<<u<<" "<<d[u]<<" "<<f[u]<<"\n";
        
    return 0;
}