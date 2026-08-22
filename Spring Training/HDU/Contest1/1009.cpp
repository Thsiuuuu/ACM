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

ll dis[405][405],x[510],y[510],k;
bool vis[405][405];
int offset=200;

void sol() {
    dis[offset][offset]=0;
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>x[i]>>y[i];
        if(x[i]==y[i]&&x[i]==0) dis[offset][offset]=1; 
    }
    if(dis[offset][offset]){cout<<"1\n";return;}
    for(int i=0;i<=400;i++) for(int j=0;j<=400;j++) vis[i][j]=false;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(q.size()){
        auto [curx,cury]=q.front();q.pop();
        for(int i=1;i<=k;i++){
            int nx=curx+x[i],ny=cury+y[i];
            if(!vis[nx+offset][ny+offset]&&nx<=200&&nx>=-200&&ny<=200&&ny>=-200){
                dis[nx+offset][ny+offset]=dis[curx+offset][cury+offset]+1;
                vis[nx+offset][ny+offset]=true;
                if(nx==0&&ny==0){cout<<dis[nx+offset][ny+offset]<<'\n';return ;}
                q.push({nx,ny});
            }
        }
    }
    cout<<"-1\n";
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