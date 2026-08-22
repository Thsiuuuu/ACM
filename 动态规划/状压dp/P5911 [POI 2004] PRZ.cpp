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
ll w,n;
const ll N=1<<17;
ll t[20],m[20];
ll f[N],T[N],M[N];
void sol() {
    cin>>w>>n;
    for(int i=0;i<n;i++){
        cin>>t[i]>>m[i];
    }
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if((mask>>i)&1) M[mask]+=m[i],T[mask]=max(T[mask],t[i]);
        }
    }
    f[0]=0;
    for(int mask=1;mask<(1<<n);mask++){
        f[mask]=1e18;
        for(int s=mask;;s=(s-1)&mask){
            if(M[s]<=w){
                f[mask]=min(f[mask],T[s]+f[mask^s]);
            }
            if(!s) break;
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