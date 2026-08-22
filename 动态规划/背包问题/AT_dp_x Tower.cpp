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
const int N=1010;
ll f[N*20];
struct P{
    ll w,s,v;
    bool operator<(const P&o)const{
        return s+w<o.s+o.w;
    }
}a[N];
int n;
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].w>>a[i].s>>a[i].v;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=20000;j++){
            f[j]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=min(a[i].w+a[i].s,20000ll);j>=a[i].w;j--){
            if(f[j-a[i].w]==-1) continue;
            f[j]=max(f[j],f[j-a[i].w]+a[i].v);
        }
    }
    cout<<*max_element(f,f+N*20);
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