#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define pii pair<ll,ll>

const int N=410;
ll mp[N][N],num[N][N];
int cnt;
int n,m,money,k;
int dir[5]={-1,0,1,0,-1};

struct Point{
    ll x,y;
};


struct node{
    ll dis;
    int u;
    bool operator<(const node&other)const{
        return dis>other.dis;
    }
};

struct Edge{
    Point u,v;
    ll w;
};

vector<Edge> edge;

bool check(ll t){
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            num[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]>t||num[i][j]) continue;
            queue<Point> q;
            q.push({i,j});
            num[i][j]=++cnt;
            while(q.size()){
                auto [x,y]=q.front();q.pop();
                for(int i=0;i<=3;i++){
                    int fx=x+dir[i],fy=y+dir[i+1];
                    if(fx>=1&&fx<=n&&fy>=1&&fy<=m&&mp[fx][fy]<=t&&num[fx][fy]==0){   
                        num[fx][fy]=cnt;
                        q.push({fx,fy});  
                    }
                }
            }
        }
    }
    
    vector<vector<pii>> e(cnt+1);
    for(int i=0;i<k;i++){
        auto [u,v,w]=edge[i];
        if((num[u.x][u.y]&&num[v.x][v.y])&&(num[u.x][u.y]^num[v.x][v.y])){
            e[num[u.x][u.y]].push_back({num[v.x][v.y],w});
        }
    }

    if(num[1][1]==num[n][m]) return true;

    vector<ll> dis(cnt+1,1e16),vis(cnt+1,0);
    priority_queue<node,vector<node>> q;
    dis[num[1][1]]=0;
    q.push({0,num[1][1]});
    while(q.size()){
        auto [d,u]=q.top();q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,w]:e[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
    if(dis[num[n][m]]<=money) return true;
    else return false;
}

void sol() {

    cin>>n>>m>>money>>k;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    edge.resize(k);
    for(int i=0;i<k;i++){
        cin>>edge[i].u.x>>edge[i].u.y>>edge[i].v.x>>edge[i].v.y>>edge[i].w;
    }
    ll l=0,r=1e12;
    ll ans=r;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}