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
#define uint unsigned int
uint seed;
inline uint getnext(){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
const int N=2e7+10;
int primes[N], tot; //素数表
bool isnp[N]; //是否为合数或1（非素数）

void initPrimes() //线性筛
{
    isnp[1] = true;
    for(ll i = 2; i < N; i ++ )
    {
        if(!isnp[i])
        {
            primes[++ tot] = i;
        }
        for(int j = 1; i*primes[j] <N; j ++)
        {
            ll t = i * primes[j];
            isnp[t] = true;
            if(i % primes[j] == 0)
            {
                break;
            }
        }
    }
}
void sol() {
    int n;cin>>n>>seed;
    vector<uint> a(n+1,0);   
    for(int i=1;i<=n;i++){
        a[i]=getnext();
    }
    for(int i=1;i<=tot;i++){
        for(ll d=1;d*primes[i]<=n;d++){
            a[primes[i]*d]+=a[d];
        }
    }
    for(int i=1;i<=n;i++) a[0]^=a[i];
    cout<<a[0];
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