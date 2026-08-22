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
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
int d1[5]={-1,1,1,-1,-1};
int d2[5]={-1,0,1,0,-1};
void sol() {
    int n,m;cin>>n>>m;
    vector<vector<char>> mp(n+1);
    for(int i=1;i<=n;i++){
        mp[i].resize(m+1);
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    auto ck=[&](int x,int y)->bool{
        return x>=1&&y>=1&&x<=n&&y<=m;
    };
    deque<pii> Q;
    vector<vector<pii>> pr(n+1,vector<pii>(m+1));
    VLL dis(n+1,VL(m+1,1e18));
    for(int i=1;i<=n;i++){
        bool f=true;
        for(int j=0;j<4;j++){
            int dx=i+d2[j],dy=1+d2[j+1];
            if(ck(dx,dy)&&mp[dx][dy]=='#'){
                f=false;
                break;
            }
        }
        if(f){
            dis[i][1]=(mp[i][1]=='.');
            pr[i][1]={0,0};
            
            if(dis[i][1]) Q.push_back({i,1});
            else Q.push_front({i,1});
        }
    }
    while(Q.size()){
        auto[x,y]=Q.front();
        Q.pop_front();
        for(int i=0;i<4;i++){
            int dx=x+d1[i],dy=y+d1[i+1];
            if(ck(dx,dy)){
                bool f=true;
                for(int j=0;j<4;j++){
                    int fx=dx+d2[j],fy=dy+d2[j+1];
                    if(ck(fx,fy)&&mp[fx][fy]=='#'){
                        f=false;
                        break;
                    }
                }
                if(f){
                    ll nd=dis[x][y]+(mp[dx][dy]=='.');
                    if(nd<dis[dx][dy]){
                        pr[dx][dy]={x,y};
                        dis[dx][dy]=nd;
                        if(mp[dx][dy]=='#') Q.push_front({dx,dy});
                        else Q.push_back({dx,dy});
                    }
                }
            }
        }
    }
    int x=0,y=0;
    for(int i=1;i<=n;i++){
        if(dis[i][m]<dis[x][y]){
            x=i,y=m;
        }
    }
    if(!x&&!y){
        cout<<"NO\n";
        return ;
    }
    while(x&&y){
        mp[x][y]='#';
        auto[dx,dy]=pr[x][y];
        x=dx,y=dy;
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<mp[i][j];
        }
        cout<<'\n';
    }
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