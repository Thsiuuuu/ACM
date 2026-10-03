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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int r(int a,int b){
    return rnd()%(b-a+1)+a;
}
const int INF=1e9;
void sol() {
    int n=r(1,15);
    VI a(n);
    cout<<n<<"\n";
    for(int i=0;i<n;i++) a[i]=r(0,20);
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("Jpai.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
