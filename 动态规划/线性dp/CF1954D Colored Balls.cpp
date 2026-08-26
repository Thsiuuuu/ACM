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
const int maxn=5e3+5;
const ll mod=998244353;
ll n,m;
ll ans;
ll a[maxn],f[maxn];
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		m+=a[i];
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=a[i];j--){
			f[j]=(f[j]+f[j-a[i]])%mod;
		}
	}
	for(int i=1;i<=m;i++){
		ans=(ans+(i+1)/2*f[i]%mod)%mod;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			ans=(ans+(a[i]-(a[i]+j+1)/2)*f[j]%mod)%mod;
		}
	}
	cout<<(ans+mod)%mod<<'\n';
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