#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int u=1;u<=n;u++){
        int k;
        cin>>u>>k;

        for(int i=0;i<k;i++){
            int v;
            cin>>v;
            adj[u].push_back(v);
        }
    }

    vector<int> dist(n+1,-1);
    queue<int> q;

    dist[1]=0;
    q.push(1);

    while(!q.empty()){

        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<i<<" "<<dist[i]<<"\n";
    }

    return 0;
}