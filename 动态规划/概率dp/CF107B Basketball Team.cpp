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
int S[1010];
void sol() {
    int n,m,h;cin>>n>>m>>h;
    int tot=0,so=0;
    for(int i=1;i<=m;i++){
        cin>>S[i];
        if(i^h) so+=S[i];
        tot+=S[i];
    }
    if(tot<n) cout<<"-1";
    else if(n-1>so) cout<<"1";
    else{
        ld ans=1;
        for(int i=-1;i>=1-n;i--) ans*=1.0*(so+i+1)/(1.0*(tot+i));
        cout<<fixed<<setprecision(7)<<(1-ans);
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