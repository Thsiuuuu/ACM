#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
/*
多测清空，long long ，是否对需要修改的变量赋值了
想不出来注意换思路
注意数据范围，枚举答案是否可行
*/
const int N=1e5+10;
bool vis[N];
ll dis[N],a[N];
vector<pll> e[N];
void sol() {
    priority_queue<pll,vector<pll>,greater<pll>> Q;
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<ll,VL>> all(k);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dis[i]=1e18;
    for(int i=0;i<k;i++){
        ll t,number;cin>>t>>number;
        all[i].first=t;
        for(int j=1;j<=number;j++){
            int id;cin>>id;
            all[i].second.push_back(id);
            Q.push({t,0});
        }
    }
    sort(all.begin(),all.end(),[&](const pair<ll,VL>&x,const pair<ll,VL>&y){
        return x.first<y.first;
    });
    for(int i=0;i<m;i++){
        ll u,v,w;cin>>u>>v>>w;
        e[u].push_back({v,w});
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0) {
            dis[i]=0;
            vis[i]=1;
            for(const auto&[v,w]:e[i]){
                Q.push({w,v});
            }
        }
    }
    int idx=0;
    while(Q.size()){
        auto[w,u]=Q.top();Q.pop();
        if(u==0){
            while(idx<k&&all[idx].first<=w){
            for(int id:all[idx].second){
                if(all[idx].first<=dis[id]){
                    dis[id]=min(dis[id],all[idx].first);
                    for(const auto&[v,val]:e[id]){
                        Q.push({val+dis[id],v});
                    }
                }
            }
            idx++;
        }
            continue;
        }
        // cout<<u<<" "<<w<<'\n';
        if(vis[u]) continue;
        // cout<<u<<" "<<a[u]<<'\n';
        if(--a[u]==0){
            if(w<dis[u]){
                dis[u]=w;
                vis[u]=1;
                for(const auto&[to,val]:e[u]){
                    Q.push({dis[u]+val,to});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dis[i]==1e18) cout<<"-1 ";
        else cout<<dis[i]<<" "; 
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}