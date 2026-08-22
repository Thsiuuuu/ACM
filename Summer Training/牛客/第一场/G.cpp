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
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
const double d=0.011;
void out(int n,int z){
    int num=0;
    for(int i=0;i<=9&&num<n;i++){
        for(int j=0;j<=9&&num<n;j++){
            cout<<z<<" "<<i*d<<" "<<j*d<<'\n';
            num++;
        }
    }
}
void sol() {
    int n;cin>>n;
    cout<<2*n<<'\n';
    out(n,0);
    out(n,1);
    // cout<<"-100 -100 -100\n100 100 100\n";
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