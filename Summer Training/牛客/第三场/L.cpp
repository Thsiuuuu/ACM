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
struct P{
    int x,y;
    ll h;
    bool operator<(const P&o)const{
        return h<o.h;
    }
};
int dir[5]={-1,0,1,0,-1};
void sol() {
    ll mx=-1;
    int n,m;cin>>n>>m;
    VLL h(n+1,VL(m+1));
    vector<vector<bool>> is(n+1,vector<bool>(m+1,false));
    priority_queue<P,vector<P>> Q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>h[i][j];
            mx=max(mx,h[i][j]);
            Q.push({i,j,h[i][j]});
        }
    }  
    auto ck=[&](int x,int y)->bool{
        return x&&y&&x<=n&&y<=m;
    };
    while(Q.size()){
        auto [x,y,ch]=Q.top();
        Q.pop();
        if(ch==mx) is[x][y]=false;
        else{
            for(int i=0;i<4;i++){
                int dx=x+dir[i],dy=y+dir[i+1];
                if(ck(dx,dy)&&h[dx][dy]>ch&&is[dx][dy]==false){
                    is[x][y]=true;
                    break;
                }
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;cin>>x>>y;
        cout<<(is[x][y]?"First\n":"Second\n");
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