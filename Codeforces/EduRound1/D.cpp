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

const int N=1010;
int res[N*N],n,m,dir[5]={-1,0,1,0,-1},idx,scc[N][N];
bool vis[N][N];
char a[N][N];
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='.'&&!vis[i][j]){
                queue<pii> Q;
                Q.push({i,j});
                vis[i][j]=1;
                idx++;
                while(Q.size()){
                    auto [x,y]=Q.front();Q.pop();
                    scc[x][y]=idx;
                    for(int k=0;k<4;k++){
                        int px=x+dir[k],py=y+dir[k+1];
                        if(px<1||px>n||py<1||py>m||vis[px][py]) continue;
                        if(a[px][py]=='*'){
                            res[idx]++;
                            continue;
                        }
                        Q.push({px,py}),vis[px][py]=1;
                    }
                }
            }
        }
    }
}

void sol() {
    int x,y;
    cin>>x>>y;
    cout<<res[scc[x][y]]<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t=1;
    cin>>n>>m;
    cin >> t;
    init();
    while (t--) {
        sol();
    }
    return 0;
}