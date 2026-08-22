#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

#define mid ((l+r)>>1)

const int N=1e5+10;
int cnt,rt1,rt2;
int ls[N*10],rs[N*10],tr[N*10];
bool vis[N*10];
ll dis[N*10];

struct Edge{
    int v;
    ll w;
};

vector<Edge> e[N*10];


int build(int l,int r,int type){
    if(l==r) return l;
    int rt=++cnt;
    ls[rt]=build(l,mid,type);
    rs[rt]=build(mid+1,r,type);
    
    if(type==0){//入树,父连子
        e[rt].push_back({ls[rt],0});
        e[rt].push_back({rs[rt],0});
    }else{//出树,子连父
        e[ls[rt]].push_back({rt,0});
        e[rs[rt]].push_back({rt,0});
    }
    return rt;
}

void update(int i,int l,int r,int jl,int jr,int v,ll w,int type){
    if(jl<=l&&r<=jr){
        if(type==0) e[v].push_back({i,w});
        else e[i].push_back({v,w});
        return ;
    }
    if(jl<=mid) update(ls[i],l,mid,jl,jr,v,w,type);
    if(jr>mid) update(rs[i],mid+1,r,jl,jr,v,w,type);
}

void debug(){
    cout<<"hek\n";
}

void sol() {
    int n,q,s;
    cin>>n>>q>>s;
    cnt=n;
    rt1=build(1,n,0),rt2=build(1,n,1);
    for(int i=1;i<=q;i++){
        int t;cin>>t;
        if(t==1){
            int v,u;ll w;
            cin>>v>>u>>w;
            e[v].push_back({u,w});
        }else{
            int v,l,r; ll w;
            cin>>v>>l>>r>>w;
            if(t==2) update(rt1,1,n,l,r,v,w,0);
            else update(rt2,1,n,l,r,v,w,1);
        }
    }
    // cout<<rt1<<" "<<rt2<<'\n';

    // debug();
    priority_queue<pli,vector<pli>,greater<pli>> Q;
    fill(dis,dis+cnt,1e18);
    Q.push(make_pair(0ll,s));
    dis[s]=0;
    while(Q.size()){
        auto [d,u]=Q.top();
        Q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto [v,w]:e[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                Q.push(make_pair(dis[v],v));
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<((dis[i]!=1e18)?dis[i]:-1)<<" ";
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