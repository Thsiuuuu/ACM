#include <bits/stdc++.h>
using namespace std;

const int N=510;
bool vis[N];
vector<int> e[N],match;


bool dfs(int u){
    for(int v:e[u]){
        if(vis[v]) continue;
        vis[v]=1;
        if(!match[v]||dfs(match[v])){
            match[v]=u;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m,tot;
    cin>>n>>m>>tot;
    match.assign(m+1,0);
    int ans=0;
    for(int i=1;i<=tot;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        ans+=dfs(i); 
    }
    cout<<ans;
    return 0;
}