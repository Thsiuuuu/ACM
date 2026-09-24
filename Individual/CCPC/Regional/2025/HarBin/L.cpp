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

#define popipa(x,y) if(ck(x,y)){Q.push({x,y,dis+1});vis[x][y]=1;}
int a[101][101],n,m,k;
pii block[10];
bool vis[101][101];
bool ck(int x,int y){
    return x>0&&y>0&&x<=n&&y<=m&&!a[x][y]&&!vis[x][y];
}
void sol() {
    cin>>n>>m>>k;
    for(int i=0;i<k;i++) cin>>block[i].first>>block[i].second;
    for(int mask=0;mask<(1<<k);mask++){
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=vis[i][j]=0;
        for(int i=0;i<k;i++){
            if((mask>>i)&1){
                for(int x=1;x<=block[i].first;x++) a[x][block[i].second]=1;
            }
            else{
                for(int x=block[i].first;x<=n;x++) a[x][block[i].second]=1;
            }
        }
        queue<tuple<int,int,int>> Q;
        for(int i=1;i<=n;i++){
            if(a[i][1]) continue;
            else{
                Q.push({i,1,0});
                vis[i][1]=1;
            }
        }
        bool is=true;
        while(Q.size()){
            auto[x,y,dis]=Q.front();
            Q.pop();
            if(y==m) {
                is=false;
                cout<<dis<<' ';
                break;
            }
            popipa(x-1,y);
            popipa(x+1,y);
            popipa(x,y+1);
        }
        if(is) cout<<"-1 ";
    }
    cout<<'\n';
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