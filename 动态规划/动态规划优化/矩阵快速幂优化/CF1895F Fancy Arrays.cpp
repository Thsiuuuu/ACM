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
const ll mod=1e9+7;
struct Mat{
	int n,m;
    VLL a;
    Mat(int n=0,int m=0,bool is=false):n(n),m(m),a(n,VL(m,0)){
        if(is){
            for(int i=0;i<min(n,m);i++) a[i][i]=1;
        }
    }
    Mat operator*(const Mat&o)const{
		Mat res(n,o.m);
        for(int i=0;i<n;i++){
            for(int k=0;k<m;k++){
                if(a[i][k]==0) continue;
                for(int j=0;j<o.m;j++){
                    res.a[i][j]+=a[i][k]*o.a[k][j];
                    res.a[i][j]%=mod;
                }
            }
        }
        return res;
    }
};
Mat ksm(Mat a,ll b){
    Mat res(a.n,a.n,true);
    while(b){
        if(b&1) res=res*a;
        a=a*a,b>>=1;
    }
    return res;
}
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod,b>>=1;
    }
    return res;
}
void sol() {
    ll n,k; int x;cin>>n>>x>>k;
    ll ans=ksm((2*k%mod+1)%mod,n-1)*((x+k)%mod)%mod;
    if(x==0){
        cout<<ans<<'\n';
        return ;
    }
    Mat F(x,1);
    for(int i=0;i<=x-1;i++){
        F.a[i][0]=1;
    }
    Mat G(x,x);
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(abs(i-j)<=k) G.a[i][j]=1;
        }
    }
    G=ksm(G,n-1);
    Mat res=G*F;
    for(int i=0;i<x;i++) ans=(ans-res.a[i][0]+mod)%mod;
    cout<<ans<<'\n';
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