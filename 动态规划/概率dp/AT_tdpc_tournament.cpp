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
ld f[12][1<<12],R[1<<12];
int n;
ld cal(int a,int b){
    return 1/(1+pow(10,(R[b]-R[a])/400));
}
void sol() {
    cin>>n;
    for(int i=1;i<=(1<<n);i++) cin>>R[i];
    for(int i=1;i<=(1<<n);i++) f[0][i]=1;
    for(int k=1;k<=n;k++){
        int l=1,r=l+(1<<k)-1,mid=l+(1<<(k-1))-1;
        while(l<=(1<<n)){
            for(int i=l;i<=mid;i++){
                for(int j=mid+1;j<=r;j++){
                    f[k][i]+=f[k-1][j]*cal(i,j);
                }
                f[k][i]*=f[k-1][i];
            }
            for(int i=mid+1;i<=r;i++){
                for(int j=l;j<=mid;j++){
                     f[k][i]+=f[k-1][j]*cal(i,j);
                }
                f[k][i]*=f[k-1][i];
            }
            l+=(1<<k);
            r+=(1<<k);
            mid=l+(1<<(k-1))-1;
        }
    }
    cout<<fixed<<setprecision(8);
    for(int i=1;i<=(1<<n);i++) cout<<f[n][i]<<'\n';
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