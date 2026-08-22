#include <bits/stdc++.h>
using namespace std;
#define int long long 


void sol(){
    int n;
    cin>>n;
    vector<vector<int>> e(n+1);
    vector<int> deg(n+1,0);
    queue<int> que;
    for(int i=0;i<n-1;i++){
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        if(x>y){
            swap(x,y);
            swap(u,v);
        }
        e[u].push_back(v);
        deg[v]++;
    }
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++){
        if(!deg[i]) que.push(i);
    }
    int cnt=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        ans[u]=cnt++;
        for(int v:e[u]){
            if(--deg[v]==0) que.push(v);
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}