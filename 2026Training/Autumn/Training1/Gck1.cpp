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
ll gcd(ll a,ll  b){
    return b?gcd(b,a%b):a;
}
int a[2501][2501];
void sol() {
    int n;cin>>n;
    int cnt=1;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) a[i][j]=cnt++;
    int cur=n*n+1;
    for(int i=1;i<n;i+=2){
        while(gcd(cur,a[i-1][n-1])>1||gcd(cur,a[i][n-2])>1||(i+1<n&&gcd(cur,a[i+1][n-1])>1)){
            cur++;
        }
        a[i][n-1]=cur++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i&&gcd(a[i][j],a[i-1][j])>1){
                cout<<i<<" "<<j<<'\n';
                cerr<<"NO\n";
                return ;
            }
            if(j&&gcd(a[i][j],a[i][j-1])>1){
                cout<<i<<" "<<j<<'\n';
                cerr<<"NO\n";
                return ;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cerr<<'\n';
    }
    cerr<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // freopen("r","Gin.txt",stdin);
    // freopen("w","Gout.txt",stdout);
    int t = 1;
    cin >> t;

    while (t--) {
        sol();
    }
    return 0;
}