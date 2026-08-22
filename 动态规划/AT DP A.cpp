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
const int N=111;
int f[N][N*N];
int a[N];
void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int x=0;x<=10000;x++){
            if(f[i-1][x]){
                if(x+a[i]<=10000) f[i][x+a[i]]=1;
                f[i][x]=1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=10000;i++) ans+=f[n][i];
    cout<<ans<<'\n';
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