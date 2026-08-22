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
const int N=3e5+10,B=512;
ll bk[N],g[N];
int n,m;
void sol() {
    cin>>n>>m;
    for(int i=1;i<N;i++){
        if(i&1) g[i]=1;
        else g[i]=g[i/2]*2;
    }
    for(int i=1;i<N;i++) g[i]+=g[i-1];
    ll ans=0;
    while(m--){
        int op;ll x;cin>>op>>x;
        if(op==1){  
            ll w;cin>>w;x^=ans,w^=ans;
            for(int i=0;x+g[i]<=n;i+=B){
                bk[x+g[i]]+=w;
            }
        }else{
            x^=ans;
            ans=0;
            for(int i=0;i<B&&x-g[i]>0;i++){
                ans+=bk[x-g[i]];
            }
            cout<<ans<<'\n';
        }
    }
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