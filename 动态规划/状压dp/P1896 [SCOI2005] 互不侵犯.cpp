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
ll f[10][1<<10][82];
bool check(ll x,ll y){
    return !(((x>>1)&y)||((x<<1)&y)||(x&y)||(y&(y>>1))||(x&(x>>1)));
}
void sol() {
    int n,k;
    cin>>n>>k;
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(ll st=0;st<(1<<n);st++){
            for(int j=0;j<=k;j++){
                for(ll other=0;other<(1<<n);other++){
                    if(j<__builtin_popcount(other)||j<__builtin_popcount(st)) continue;
                    if(check(st,other)){
                        f[i][st][j]+=f[i-1][other][j-__builtin_popcount(st)];
                    }
                }   
            }
        }
    }
    ll ans=0;
    for(ll mask=0;mask<(1<<n);mask++){
        ans+=f[n][mask][k];
    }
    cout<<ans;
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