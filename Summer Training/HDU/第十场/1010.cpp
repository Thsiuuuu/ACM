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
const int N=1e5+10;
int f[N],n,m,len,a[N],b[N];
map<int,int>ton;
void sol() {
    len=0;
    ton.clear();
    cin>>n>>m;
    for(int i=0;i<=n*m;i++) f[i]=0;
    for(int i=1;i<=n*m;i++) cin>>a[i];    
    for(int i=1;i<=n*m;i++) cin>>b[i];
    for(int i=1;i<=n*m;i++){
        ton[b[i]]=i;
    }
    for(int i=1;i<=n*m;i++) a[i]=ton[a[i]];
    for(int i=1;i<=n*m;i++){
        auto it=lower_bound(f,f+len+1,a[i]);
        if(f+len+1==it) f[++len]=a[i];
        else *it=a[i];    
    }
    cout<<n*m-len<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}