#include <bits/stdc++.h>
using namespace std;

#define ll long long 

const int N=1e5+2;
struct edge{
    int v,w;
};
vector<edge> e[N];
bool vis[N];

struct node{
    ll d;
    int pos;
    bool operator<(const node&other)const{
        return d>other.d;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    ll h;
    cin>>h;
    vector<int> number(3);
    for(int i=0;i<3;i++){
        cin>>number[i];
    }
    sort(number.begin(),number.end());

    for(int u=0;u<number[0];u++){
        e[u].push_back({(u+number[1])%number[0],number[1]});
        e[u].push_back({(u+number[2])%number[0],number[2]});
    }
    
    priority_queue<node,vector<node>> q;
    vector<ll> dis(number[0],INT64_MAX);
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
    for(int u=0;u<number[0];u++){
        if(dis[u]<=h-1){
            ans+=(h-1-dis[u])/number[0]+1;
        }
    }
    cout<<ans-1;
    return 0;
}