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

#define mat VLL
const ll mod=1e9+7;
mat mul(mat a,mat b){
    mat res(a.size(),VL(b[0].size(),0));
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            for(int k=0;k<a[0].size();k++){
                res[i][j]+=a[i][k]*b[k][j];
                res[i][j]%=mod;
            }
        }
    }
    return res;
}
mat ksm(mat a,ll b){
    int siz=a[0].size();
    mat res (siz,VL (siz,0));
    for(int i=0;i<siz;i++) res[i][i]=1;
    while(b){
        if(b&1){
            res=mul(res,a);
        }
        a=mul(a,a),b>>=1;
    }
    return res;
}
void sol() {
    int h,r;cin>>h>>r;
    mat a(r,VL(r,0)),b=a; 
    for(int i=0;i<r;i++) for(int j=0;j<r;j++) cin>>a[i][j];   
    for(int i=0;i<r;i++) b[i][i]=1;
    VLL dp;
    for(int u=0;u<r;u++){
        dp.assign(r,VL(1<<r,0));
        int R=1<<u;
        dp[u][R]=1;
        for(int mask=R;mask<(1<<r);mask++){
            for(int i=0;i<r;i++){
                if(!((mask>>i)&1)) continue;
                for(int j=0;j<r;j++){
                    if(i==j||!a[i][j]||((mask>>j)&1)) continue;
                    dp[j][mask|(1<<j)]+=dp[i][mask];
                    dp[j][mask|(1<<j)]%=mod;
                }
                if(mask>R) b[u][i]=(b[u][i]+dp[i][mask])%mod;
            }
        }
    }
    b=ksm(b,h);
    mat f(r,VL(1,0));
    f[0][0]=1;
    f=mul(b,f);
    cout<<f[0][0]<<'\n';
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