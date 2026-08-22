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
constexpr int N = 1e7 + 10,M=2e6+10;

int primes[N], tot; 
bool isnp[N]; 
int phi[N]; 
ll a[M],g[N],ans[1002];

void initPrimes()
{
    phi[1]=1;
    isnp[1] = true;
    for(ll i = 2; i <N; i ++ )
    {
        if(!isnp[i])
        {
            primes[++ tot] = i;
            phi[i] = i - 1;
        }
        for(int j = 1; i*primes[j] <N; j ++)
        {
            ll t = i * primes[j];
            isnp[t] = true;
            if(i % primes[j] == 0)
            {
                phi[t] = phi[i] * primes[j];
                break;
            }
            phi[t] = phi[i] * (primes[j] - 1);
        }
    }
}
void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=N-9;i++){
        g[i]=0;
    }
    for(int i=1;i<=n;i++){
        g[a[i]]=phi[a[i]];
    }
    for(int i=1;i<=tot;i++){
        for(ll d=(N-10)/primes[i];d>=1;d--){
            g[d]=max(g[d],g[d*primes[i]]);
        }
    }
    for(int i=1;i<=N-10;i++){
        g[i]=i*g[i]/phi[i];
    }
    for(int i=1;i<=tot;i++){
        for(ll d=1;primes[i]*d<=(N-10);d++){
            g[d*primes[i]]=max(g[d*primes[i]],g[d]);
        }
    }
    for(int i=1;i<=N-10;i++) g[i]=phi[i]*g[i];
    for(int i=0;i<1000;i++) ans[i]=0;
    for(int i=1;i<=N-10;i++){
        ans[i%1000]^=((i+999)/1000*g[i]);
    }
    for(int i=0;i<1000;i++){
        cout<<ans[i]<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // freopen("1003input.txt","r",stdin);
    // freopen("1003output.txt","w",stdout);
    cin >> t;
    initPrimes();
    while (t--) {
        sol();
    }
    return 0;
}