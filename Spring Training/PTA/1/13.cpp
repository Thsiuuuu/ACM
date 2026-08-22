#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  

int dir[5]={-1,0,1,0,-1};
ll mp[110][110],dis[110][110];
int n,m;
int x[11000],y[11000];
bool vis[110][110];
int sx,sy,k;

struct node{
    int x,y;
    ll d;
};

struct p{
    int i;
    ll t=1e18;
    bool operator<(const p& other)const{
        return t<other.t;
    }
};

void sol() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            dis[i][j]=1e18;
            if(mp[i][j]==2) sx=i,sy=j;  
        }
    }
    cin>>k;
    vector<p> tim(k+1);
    for(int i=1;i<=k;i++){
        cin>>y[i]>>x[i];
        tim[i].i=i;
    }
    queue<node> q;
    q.push({sx,sy,0});
    vis[sx][sy]=1;
    while(q.size()){
        auto [curx,cury,d]=q.front();q.pop();
        dis[curx][cury]=d;
        for(int i=0;i<=3;i++){
            int x=curx+dir[i],y=cury+dir[i+1];
            if(vis[x][y]||x<1||x>n||y<1||y>m||mp[x][y]!=1) continue;
            vis[x][y]=1;
            q.push({x,y,d+1});
        }
    }
    for(int i=1;i<=k;i++){
        tim[i].t=dis[x[i]][y[i]];
    }

    sort(tim.begin()+1,tim.end());
    bool f=true;
    for(int i=1;i<=k;i++){
        int j=i;
        if(tim[i].t==1e18) break;
        while(j<=k&&tim[j].t==tim[i].t){
            j++;
        }
        if(j<=i+1){
            f=false;
            cout<<tim[i].i<<" "<<tim[i].t;
            break;
        }else i=j-1;
    }
    if(f){
        cout<<"No winner.";
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