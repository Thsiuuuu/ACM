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
const int N=2e7+10,M=2e5+10;
ll f[N],a[M],cnt[N];
int n;
int primes[N], tot; 
bool isnp[N];
int phi[N];

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
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;   
    }
    for(int i=1;i<=tot;i++){
        for(ll d=(N-10)/primes[i];d>=1;d--){
            cnt[d]+=cnt[d*primes[i]];
        }
    }
    for(int i=1;i<=N-10;i++) f[i]=i*cnt[i];
    for(ll d=N-10;d>=1;d--){
        for(int i=1;i<=tot&&d*primes[i]<=N-10;i++){
            f[d]=max(f[d],f[d*primes[i]]+(-cnt[primes[i]*d]+cnt[d])*d);
        }
    }
    cout<<f[1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    initPrimes();
    while (t--) {
        sol();
    }
    return 0;
}