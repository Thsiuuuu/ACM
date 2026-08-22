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
const int N=1e6+10;
const ll mod=998244353;
int primes[N],cnt,mu[N],a[(int)(2e5+10)];
ll F[N],f[N];
bool vis[N];
void init( ){
    mu[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i])
            primes[cnt++]=i,mu[i]=-1;
        for(int j=0;j<cnt&&primes[j]*i<N;j++){
            vis[primes[j]*i]=true;
            if(i%primes[j]==0){
                break;
            }
            mu[primes[j]*i]=-mu[i];
        }
    }
    // for(int i=1;i<N;i++){
    //     //计算莫比乌斯函数的前缀和
    //     s[i]=s[i-1]+mu[i];
    // }
}
void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll S=0;
    f[1]=1;
    for(int i=1;i<=n;i++){
        if(i!=1){
            for(ll k=1;k*k<=a[i];k++){
                if(a[i]%k==0){
                    f[i]=(f[i]+mu[k]*F[k]%mod)%mod;
                    if(k*k!=a[i]){
                        f[i]=(f[i]+mu[a[i]/k]*F[a[i]/k]%mod)%mod;
                    }
                }
            }
            f[i]=(S-f[i]+mod)%mod;
        }
        for(ll k=1;k*k<=a[i];k++){
            if(a[i]%k==0){
                F[k]=(F[k]+f[i])%mod;
                if(k*k!=a[i]){
                    F[a[i]/k]=(F[a[i]/k]+f[i])%mod;
                }
            }
        }
        S=(S+f[i])%mod;
    }
    cout<<f[n];
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