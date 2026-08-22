#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long 

struct Edge{
    int v;
    int w,cal;
};

const int N=510;
vector<Edge> e[N];


void sol(){
    int b,n,m,k;
    cin>>b>>n>>m>>k;

    for(int i=0;i<m;i++){
        int u,v,w,cal; 
        cin>>u>>v>>w>>cal;
        e[u].push_back({v,w,cal});
        e[v].push_back({u,w,cal});       
    }

    while(k--){
        int s;
        cin>>s;
        priority_queue<pii,vector<pii>,greater<pii>> q;
        vector<bool> vis(n+1,false);
        vector<int> dis(n+1,INT32_MAX),mood(n+1,0);
        q.push({0,s});
        dis[s]=0;
        while(q.size()){
            auto [d,u]=q.top();q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(auto[v,w,cal]:e[u]){
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w,mood[v]=mood[u]+cal;
                    q.push({dis[v],v});
                }else if(dis[v]==dis[u]+w) mood[v]=max(mood[v],mood[u]+cal);
            }
        }
        // for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
        // cout<<'\n';
        vector<int> res;
        for(int i=1;i<=n;i++){
            if(i!=s&&dis[i]<=b){
                res.push_back(i);
            }
        }
        sort(res.begin(),res.end());
        if(res.size()==0) cout<<"T_T\n";
        else{
            for(int i=0;i<res.size();i++){
                if(i) cout<<" ";
                cout<<res[i]; 
            }
            cout<<'\n';
            sort(res.begin(),res.end(),[&](int a,int b)->bool{
                if(mood[a]==mood[b]) return a<b;
                return mood[a]>mood[b];
            });
            for(int i=0;i<res.size()&&mood[res[i]]==mood[res[0]];i++){
                if(i) cout<<" ";
                cout<<res[i];
            }
            cout<<'\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}