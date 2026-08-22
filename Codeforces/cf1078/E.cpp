#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long
#define pii pair<int,int> 

void out(){
    cout<<"hel\n";
}

void sol() {
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n+1,vector<ll>(m+1,-1e18)),fz,fn;
    vector<vector<pii>> fx(n+1,vector<pii>(m+1)),fy;
    fz=fn=a;
    fy=fx;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    fz[1][1]=a[1][1],fn[n][m]=a[n][m];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i*j==1ll) continue;
            fz[i][j]=max({fz[i-1][j],fz[i][j-1]});
            fz[i][j]+=a[i][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(i==n&&j==m) continue;
            if(i+1<=n) fn[i][j]=max(fn[i][j],fn[i+1][j]);
            if(j+1<=m) fn[i][j]=max(fn[i][j],fn[i][j+1]);
            fn[i][j]+=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j==1) fx[i][j]={i,j};
            else{
                auto [x,y]=fx[i][j-1];
                if(fz[i][j]+fn[i][j]-a[i][j]>fz[x][y]+fn[x][y]-a[x][y]) fx[i][j]={i,j};
                else fx[i][j]={x,y};
            }
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(i==1) fy[i][j]={i,j};
            else{
                auto [x,y]=fy[i-1][j];
                if(fz[i][j]+fn[i][j]-a[i][j]>fz[x][y]+fn[x][y]-a[x][y]) fy[i][j]={i,j};
                else fy[i][j]={x,y};
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<fz[i][j]<<" "<<fn[i][j]<<'\n';
    //     }
    // }
    ll ans=1e18;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll res=-1e18;
            if(i+1<=n&&j>=2){
                auto&[x,y]=fx[i+1][j-1];
                res=max(res,fz[x][y]+fn[x][y]-a[x][y]);
            }
            if(j+1<=m&&i>=2){
                auto&[x,y]=fy[i-1][j+1];
                res=max(res,fz[x][y]+fn[x][y]-a[x][y]);
            }
            res=max(res,fz[i][j]+fn[i][j]-3*a[i][j]);
            ans=min(ans,res);
        }
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}