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
/*
多测清空，long long ，是否对需要修改的变量赋值了
想不出来注意换思路
注意数据范围，枚举答案是否可行
*/
const int M=1001;
const ll mod=998244353;
ll inv[M],fac[M];

ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}

void init(){
    fac[0]=fac[1]=inv[1]=inv[0]=1;
    for(int i=2;i<M;i++) fac[i]=fac[i-1]*i%mod;
    inv[M-1]=ksm(fac[M-1],mod-2);
    for(int i=M-2;i>=2;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

ll C(ll n,ll m){
    if(m>n||m<0||n<0) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod; 
}
const int N=510;
ll a[N],f[N][N];
int n;
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    f[0][1]=1;
    ll cursum=0;
    for(int i=0;i<n;i++){
        for(int j=2;j<=cursum+1;j++){
            for(int x=0;x<a[i+1];x++){
                for(int k=1;k<j;k++){
                    f[i+1][x+k+1]+=f[i][j]*C(a[i+1]-x-1+j-k-1,a[i+1]-x-1)%mod;
                    f[i+1][x+k+1]%=mod;
                }
            }
        }
        for(int j=1;j<=cursum+1;j++){
            f[i+1][j+a[i+1]]+=f[i][j];
            f[i+1][j+a[i+1]]%=mod;
        }
        cursum+=a[i+1];
    }
    ll ans=0;
    for(int i=1;i<=cursum+1;i++){
        ans=(ans+f[n][i])%mod;
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    init();
    while (t--) {
        sol();
    }
    return 0;
}