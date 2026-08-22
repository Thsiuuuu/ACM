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

ll a[21][21];
map<ll,ll> mp[21][21];
int n,m;
ll k,ans=0;
int dx[2]={0,1},
    dy[2]={1,0};

void dfs(int x,int y,ll pre,int is){
    if((x+y-2)==((n+m-2)/2)){
        if(is==-1) ans+=mp[x][y][pre^k];
        else mp[x][y][pre^a[x][y]]++;
    }else{
        for(int i=0;i<2;i++){
            int px=x+is*dx[i],py=y+is*dy[i];
            if(px<1||px>n||py<1||py>m) continue;
            dfs(px,py,pre^a[x][y],is);
        }
    }
}

void sol() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    dfs(1,1,0,1);
    dfs(n,m,0,-1);
    cout<<ans;
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