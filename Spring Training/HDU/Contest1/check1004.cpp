#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  

ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a;
        b>>=1,a=a*a;
    }
    return res;
}

void sol() {
    int i=1;
    while(ksm(2,i)<=(int)(1e6)){
        i++;
    }
    cout<<i;
    // // cout<<ksm(2,i)<<'\n';
    // cout<<fixed<<setprecision(16)<<(double)(1048576/(ll)(ksm(2,63)));
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