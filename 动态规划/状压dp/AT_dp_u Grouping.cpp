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
const int N=187;
ll a[N][N],f[1<<17];
int n;
void sol() {
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    f[0]=0;
    for(int mask=1;mask<(1<<n);mask++){
        for(int st=mask;;st=(st-1)&mask){
            if(st==0) break;
            if(st==mask){
                for(int i=0;i<n;i++){
                    if((mask>>i)%2==0) continue;
                    for(int j=i+1;j<n;j++){
                        if((mask>>j)%2==0) continue;
                        f[mask]+=a[i][j];
                    }
                }
            }else{
                f[mask]=max(f[mask],f[st]+f[mask^st]);
            }
        }
    }
    cout<<f[(1<<n)-1];
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