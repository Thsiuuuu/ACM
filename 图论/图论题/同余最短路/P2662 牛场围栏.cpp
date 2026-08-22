#include <bits/stdc++.h>
using namespace std;

#define ll long long 

const int N=3010;
struct edge{
    int v;
    ll w;
};
vector<edge> e[N];

struct node{
    ll d,pos;
    bool operator<(const node&other)const{
        return d>other.d;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=1;j<=m;j++){
            if(a[i]-j>=1){
                a.push_back(a[i]-j);
            }
        }
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    vector<ll> dis(a[0],INT64_MAX);
    for(int i=0;i<a[0];i++){
        for(int j=0;j<a.size();j++){
            e[i].push_back({(i+a[j])%a[0],a[j]});
        }
    }
    priority_queue<node,vector<node>> q;
    vector<bool> vis(a[0],0);
    dis[0]=0;
    q.push({0,0});
    while(q.size()){
        auto [d,u]=q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,w]:e[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    q.push({dis[v],v});
                }
            }
        }
    }
    ll ans=-1;
    for(int i=0;i<a[0];i++){
        if(dis[i]==i){
            continue;
        }
        if(dis[i]==INT64_MAX){
            cout<<"-1";
            return 0;
        }else{
            ans=max(ans,dis[i]-a[0]);
        }
    }
    cout<<ans;
    return 0;
}