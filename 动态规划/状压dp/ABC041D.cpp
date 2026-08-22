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
const int N=20;
int n,m;
ll in[N],f[1<<N];
void sol() {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        u--,v--;
        in[v]|=(1<<u);
    }
    f[0]=1;
    for(ll mask=1;mask<(1<<n);mask++){
        for(int u=0;u<n;u++){
            if(((mask>>u)&1)&&!(in[u]&mask)){
                f[mask]+=f[mask^(1<<u)];
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