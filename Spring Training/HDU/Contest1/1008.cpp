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

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

void sol() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> a(n+1,1);
    for(int i=1;i<=m;i++){
        int x,y;ll g;
        cin>>x>>y>>g;
        if(a[x]%g){
            ll tmp=g/gcd(a[x],g);
            a[x]*=tmp;
        }
        if(a[y]%g){
            ll tmp=g/gcd(a[y],g);
            a[y]*=tmp;
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        cout<<gcd(a[x],a[y])<<'\n';
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