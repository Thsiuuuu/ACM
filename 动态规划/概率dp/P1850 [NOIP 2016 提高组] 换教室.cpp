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
ll dis[310][310];
int c[2010],d[2010];
double p[2010];
double f[2010][2010][2];
int n,m,v,e;
void sol() {
    cin>>n>>m>>v>>e;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(i^j) dis[i][j]=INT32_MAX;
        }
    }
    for(int i=1;i<=e;i++){
        int a,b;
        ll w;
        cin>>a>>b>>w;
        dis[a][b]=min(w,dis[a][b]);
        dis[b][a]=min(w,dis[b][a]);
    }
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j][0]=f[i][j][1]=INT32_MAX;
        }
    }
    f[1][1][1]=f[1][0][0]=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=min(i,m);j++){
            
            f[i][j][0]=f[i-1][j][0]+dis[c[i-1]][c[i]];
            if(j) f[i][j][0]=min(f[i][j][0],
                                 f[i-1][j][1]+(1-p[i-1])*dis[c[i-1]][c[i]]+p[i-1]*dis[d[i-1]][c[i]]);
            if(j){
                f[i][j][1]=min(f[i-1][j-1][0]+dis[c[i-1]][c[i]]*(1-p[i])+dis[c[i-1]][d[i]]*p[i],
                               f[i-1][j-1][1]+p[i-1]*p[i]*dis[d[i-1]][d[i]]+(1-p[i-1])*p[i]*dis[c[i-1]][d[i]]+p[i-1]*(1-p[i])*dis[d[i-1]][c[i]]+(1-p[i-1])*(1-p[i])*dis[c[i-1]][c[i]]);
            }
        }
    }
    double ans=1e9;
    for(int j=0;j<=m;j++){
        for(int k=0;k<=1;k++){
            ans=min(ans,f[n][j][k]);
        }
    }
    cout<<fixed<<setprecision(2)<<ans;
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