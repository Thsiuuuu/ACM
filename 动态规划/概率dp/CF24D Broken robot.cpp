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
const int N=1010;
double f[N][N],a[N][N];
int n,m,x,y;
void cal(int x){
    for(int i=1;i<=m;i++){
        if(i==1){
            a[1][1]=2,
            a[1][2]=-1,
            a[1][m+1]=f[x+1][1]+3;
        }else if(i==m){
            a[m][m-1]=-1;
            a[m][m]=2,
            a[m][m+1]=f[x+1][m]+3;
        }else{
            a[i][i-1]=-1,
            a[i][i]=3,
            a[i][i+1]=-1,
            a[i][m+1]=f[x+1][i]+4;
        }
    }
    for(int i=1;i<=m-1;i++){
        double k=a[i+1][i]/a[i][i];
        a[i+1][i]=0;
        a[i+1][i+1]-=k*a[i][i+1];
        a[i+1][m+1]-=k*a[i][m+1];
    }
    f[x][m]=a[m][m+1]/a[m][m];
    for(int i=m-1;i>=1;i--){
        f[x][i]=(a[i][m+1]-a[i][i+1]*f[x][i+1])/a[i][i];
    }
}

void sol() {
    cin>>n>>m>>x>>y;
    if(m==1){
        cout<<2*(n-x);
        return ;
    }
    for(int i=1;i<=m;i++) f[n][i]=0;
    for(int i=n-1;i>=1;i--){
        cal(i);
    }   
    cout<<fixed<<setprecision(10)<<f[x][y];
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