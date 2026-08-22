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
const int N=1010;
char mp[N][N];
bool vis[N][N];
int num[N][N],cnt,siz[N*N];
int dir[5]={-1,0,1,0,-1};
void sol() {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]!='*'&&!vis[i][j]){
                queue<pii >Q;
                Q.push({i,j});
                vis[i][j]=1;
                num[i][j]=++cnt;
                while(Q.size()){
                    auto [x,y]=Q.front();
                    siz[cnt]++;
                    Q.pop();
                    for(int k=0;k<4;k++){
                        int dx=x+dir[k],dy=y+dir[k+1];
                        if(!dx||dx>n||!dy||dy>m) continue;
                        if(vis[dx][dy]||mp[dx][dy]=='*') continue;
                        Q.push({dx,dy});
                        num[dx][dy]=cnt;
                        vis[dx][dy]=1;
                    }
                }
            }
        }
    }
    // for(int i=1;i<=cnt;i++){
    //     cout<<siz[i]<<' ';
    // }
    // cout<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='.') cout<<".";
            else{
                int ans=1;
                set<int> S;
                for(int k=0;k<4;k++){
                    int dx=i+dir[k],dy=j+dir[k+1];
                    if(!dx||dx>n||!dy||dy>m) continue;
                    if(mp[dx][dy]=='*') continue;
                    if(S.find(num[dx][dy])==S.end()){
                        ans+=siz[num[dx][dy]];
                        S.insert(num[dx][dy]);
                    }
                }
                cout<<ans%10;
            }
        }
        cout<<'\n';
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