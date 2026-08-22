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
    ll k,n;cin>>n>>k;
    if(k>32) cout<<"1\n";
    else{
        ll x=1;
        while(ksm(x,k)<=n) x++;
        cout<<x-1<<'\n';
    }
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