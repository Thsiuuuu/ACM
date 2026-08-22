#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

const int N=1e6+10;
const ll mod=998244353;
ll f[N];


void init(){
    f[1]=1,f[2]=2,f[3]=4,f[4]=6,f[5]=9,f[6]=13,f[7]=17,f[8]=22,f[9]=28,f[10]=36;
    for(int i=11;i<N;i++){
        f[i]=(2*f[i-4]+10)%mod;
    }
}

void sol() {
    // for(int i=1;i<=10;i++) cout<<f[i]<<'\n';
    int n;
    cin>>n;
    cout<<f[n]<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    init();
    while (t--) {
        sol();
    }
    return 0;
}