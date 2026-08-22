#include <bits/stdc++.h>
using namespace std;
/*



*/


const int N=5e3+10;
struct edge{
    int v,w;
};

vector<edge> e[N];
vector<int> cnt(N,0),vis(N,0),dis(N,0);

bool spfa(int n,int s){
    for(int i=1;i<=n;i++){
        dis[i]=INT32_MAX;
    }
    queue<int> q;
    q.push(s);
    vis[s]=1,dis[s]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(auto [v,w]:e[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n){
                    return false;
                }
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c,op;
        cin>>op;
        if(op==1){
            cin>>a>>b>>c;
            e[a].push_back({b,-c});
        }else if(op==2){
            cin>>a>>b>>c;
            e[b].push_back({a,c});
        }else{
            cin>>a>>b;
            e[a].push_back({b,0});
            e[b].push_back({a,0});
        }
    }
    for(int i=1;i<=n;i++){
        e[0].push_back({i,0});
    }
    if(spfa(n,0)){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }

    return 0;
}