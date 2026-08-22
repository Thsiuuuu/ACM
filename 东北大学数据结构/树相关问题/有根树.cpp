#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin>>n;
    vector<vector<int>> children(n);
    vector<int> parent(n,-1);
    vector<int> depth(n,-1);

    for(int i=0;i<n;i++){
        int id,k;
        cin>>id>>k;
        children[id].resize(k);
        for(int j=0;j<k;j++){

            cin>>children[id][j];
            int c=children[id][j];
            parent[c]=id;
        }
    }

    int root=-1;
    for(int i=0;i<n;i++){
        if(parent[i]==-1){
            root=i;
            break;
        }
    }

    queue<int> q;
    q.push(root);
    depth[root]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:children[u]){
            depth[v]=depth[u]+1;
            q.push(v);
        }
    }

    for(int id=0;id<n;id++){
        string type;
        if(parent[id]==-1) type="root";
        else{
            if(children[id].empty()) type="leaf";
            else type="internal node";
        }

        cout<<"node "<<id<<": parent = "<<parent[id]<<", depth = "<<depth[id]<<", "<<type<<", [";
        for(int i=0;i<children[id].size();i++){
            if(i) cout<<", ";
            cout<<children[id][i]; 
        }
        cout<<"]\n";
    }

    return 0;
}