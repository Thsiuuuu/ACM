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
constexpr int N = 1e5 + 10;

int primes[N], tot; //素数表
bool isnp[N]; //是否为合数或1（非素数）
int phi[N]; //欧拉函数

void initPrimes() //线性筛
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
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=(ll)(n/i)*(n/i)*phi[i];
    }
    cout<<ans;
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