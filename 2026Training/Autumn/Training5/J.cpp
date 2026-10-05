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
const int N=5e4+10;
int w,n;
ll f[1<<14],a[14],sum[1<<14];
void sol() {
    cin>>n>>w;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a[x-1]++;
    }
    for(int mask=0;mask<(1<<13);mask++){
        for(int i=0;i<13;i++){
            if((mask>>i)&1) sum[mask]+=a[i];
        }
    }
    for(int mask=0;mask<(1<<13);mask++) f[mask]=1e9;
    // cout<<sum[(1<<13)-1]<<'\n';
    f[0]=0;
    int all=(1<<13)-1;
    for(int mask=1;mask<(1<<13);mask++){
        for(int st=(mask-1)&mask;;st=(st-1)&mask){
            int other=mask^st;
            if(sum[other]<=w){
                f[mask]=min(f[mask],f[st]+1);
            }
            if(st==0) break;
        }
    }
    cout<<f[(1<<13)-1];
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