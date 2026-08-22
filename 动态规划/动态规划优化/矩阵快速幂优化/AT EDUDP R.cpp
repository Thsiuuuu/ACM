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
const ll N=52,mod=1e9+7;
VLL mul(const VLL&a,const VLL& b){
    int siz=a.size();
    VLL f(siz,VL(siz,0));
    for(int i=0;i<siz;i++){
        for(int j=0;j<siz;j++){
            for(int k=0;k<siz;k++){
                f[i][j]+=a[i][k]*b[k][j]%mod;
                f[i][j]%=mod;
            }
        }
    }
    return f;
}
VLL ksm(VLL a,ll b){
    int siz=a.size();
    VLL res(siz,VL(siz,0));
    for(int i=0;i<siz;i++){
        res[i][i]=1;
    }
    while(b){
        if(b&1){
            res=mul(res,a);
        }
        b>>=1;
        a=mul(a,a);
    }
    return res;
}
void sol() {
    int n;ll k;cin>>n>>k;
    VLL Q(n,VL(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>Q[j][i];
        }
    }
    Q=ksm(Q,k);
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+=Q[i][j];
            ans%=mod;
        }
    }
    cout<<ans;
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