#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

/*
    图上进行q次bfs会超时，这里采用并查集划分联通块
*/



int find(int u){
    if(parent[u]!=u){
        parent[u]=find(parent[u]);
    }

    return parent[u];
}


void unite(int u,int v){
    parent[find(u)]=find(v);
}

bool con(int u,int v){
    return find(u)==find(v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;

    parent.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    for(int i=0;i<m;i++){
        int s,t;
        cin>>s>>t;
        unite(s,t);
    }

    int q;
    cin>>q;
    while(q--){
        int s,t;
        cin>>s>>t;
        cout<<(con(s,t)?"yes":"no")<<"\n";
    }

    return 0;

}