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

// double pw;
// void init(){
//     // pw=sqrt(2)/2;
//     // cout<<pw<<'\n';
// }

// ll gcd(ll a,ll b){
//     return b?gcd(b,a%b):a;
// }

void sol() {
    int n;
    while(cin>>n){
        ll ans=0;
        map<ll,int> mp1,mp2;
        vector<ll> x(n),y(n);
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
            ll b1=y[i]-x[i],
               b2=y[i]+x[i];
            mp1[b1]++,mp2[b2]++;
        }
        for(int i=0;i<n;i++){
            ll b1=y[i]-x[i],
               b2=y[i]+x[i];
            ans+=mp1[b1]-1,
            ans+=mp2[b2]-1;
        }
        double res=((double)ans)/(double)((ll)n*n);
        cout<<fixed<<setprecision(8)<<res<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    // init();
    while (t--) {
        sol();
    }
    return 0;
}