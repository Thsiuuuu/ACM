#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int N=5e5+10;

struct edge{
    int v;
    ll w;
};
vector<edge> e[N];

struct node{
    ll d;
    int u;
    bool operator<(const node&other)const{
        return d>other.d;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    int n;
    ll l,r;
    cin>>n>>l>>r;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    int base;
    for(int i=0;i<a.size();i++){
        if(a[i]){
            base=a[i];
            break;
        }
    }

    for(int i=0;i<base;i++){
        for(int j=0;j<a.size();j++){
            e[i].push_back({(i+a[j])%base,a[j]});
        }
    }
    priority_queue<node,vector<node>> q;
    vector<ll> dis(base,INT64_MAX);
    vector<bool> vis(base,false);
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
    ll ans=0;
    for(int i=0;i<base;i++){
        if(r>=dis[i]){
            ans+=(r-dis[i])/base+1;
        }
        if(l-1>=dis[i]){
            ans-=(l-1-dis[i])/base+1;
        }
    }
    cout<<ans;
    return 0;
}
