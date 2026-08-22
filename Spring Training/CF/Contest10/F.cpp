#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

int n,m;
bool vis[1010][1010];
char mp[1010][1010];
int dir[5]={-1,0,1,0,-1};

struct node{
    int x,y;
    ll res;
    node(){}
    node(int x,int y,ll res):x(x),y(y),res(res){}
    bool operator<(const node&other)const{
        return res<other.res;
    }
};

bool check(ll mid){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i][j]=false;
        }
    }   
    priority_queue<node,vector<node>> q;
    q.push({1,1,mid});
    while(q.size()){
        auto [x,y,res]=q.top();
        q.pop();
        if(vis[x][y]) continue;
        vis[x][y]=1;
        if(x==n&&y==m) return true;
        for(int i=0;i<4;i++){
            int fx=x+dir[i],fy=y+dir[i+1];
            if(fx<=0||fx>n||fy<=0||fy>m) continue;
            if(mp[x][y]=='#'&&res==0) continue;
            if(mp[x][y]=='#') q.push({fx,fy,res-1});
            else{
                if(res<mid&&res>0){
                    q.push({fx,fy,res-1});
                }else q.push({fx,fy,res});
            }
        }
    }
    return false;
}

void sol() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    ll l=0,r=n+m;
    ll ans;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<ans<<'\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}