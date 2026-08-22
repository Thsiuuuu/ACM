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
// ll a[24][24];
int n;
int tot=0;
void sol() {
    // cin>>n;
    // for(int i=0;i<3*n;i++) {
    //     for(int j=0;j<3*n;j++){
    //         cin>>a[i][j];
    //     }
    // }
    for(int mask=0;mask<(1<<24);mask++){
        if(__builtin_popcount(mask)%3) continue;
            if(__builtin_popcount(mask)%3==0) tot++;
//        for(int st=mask;;st=(st-1)&mask){
//            if(st==0 ) break;
//        }
    }
    cout<<tot<<'\n';
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