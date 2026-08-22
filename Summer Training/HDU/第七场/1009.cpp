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
const int N=503;
ll f[N][N],g[N][N],k[N],c[N],K[N];

void sol() {
    int n,m,s;cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        cin>>k[i]>>c[i];
    }
    for(int i=1;i<=n;i++) cin>>K[i];
    for(int i=0;i<=m;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=1e18;
        }
    }
    f[0][s]=0;
    for(int i=1;i<=m;i++){
        for(int x=0;x<=m;x++){
            for(int y=1;y<=n;y++){
                g[x][y]=f[x][y];
            }
        }
        for(int h=0;h<=m;h++){
            deque<int> Q;
            for(int st=max(1ll,2-k[i]);st<=min(k[i],1ll*n);st++){
                while(Q.size()&&g[h][Q.back()]>g[h][st]) Q.pop_back();
                Q.push_back(st);
            }
            for(int p=1;p<=n;p++){
                f[h][p]=1e18;
                if(Q.size()){
                    f[h][p]=g[h][Q.front()];
                }
                while(Q.size()&&Q.front()<p+2-k[i]) Q.pop_front();
                if(p+k[i]<=n){
                    while(Q.size()&&g[h][Q.back()]>g[h][p+k[i]]) Q.pop_back();
                    Q.push_back(p+k[i]);
                }
                ll INF=1e18;
                if(p-k[i]>=1) INF=min(INF,g[h][p-k[i]]);
                if(p+k[i]<=n) INF=min(INF,g[h][p+k[i]]);
                f[h][p]=min(f[h][p],INF+c[i]);
                if(p==1&&h>=1){
                    for(int x=1;x<=min((ll)n,k[i]);x++) f[h][p]=min(f[h][p],g[h-1][x]+c[i]);
                    f[h][p]=min((ll)(1e18),f[h][p]);
                }
                if(p==n&&h>=1){
                    for(int x=max(1ll,n-k[i]+1);x<=n;x++) f[h][p]=min(f[h][p],g[h-1][x]+c[i]);
                    f[h][p]=min((ll)(1e18),f[h][p]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        bool is=true;
        for(int j=m;j>=0;j--){
            if(f[j][i]<=K[i]){
                cout<<j<<' ';
                is=false;
                break;
            }
        }
        if(is) cout<<"-1 ";
    }
    cout<<'\n';
    // cout<<"hel\n";
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