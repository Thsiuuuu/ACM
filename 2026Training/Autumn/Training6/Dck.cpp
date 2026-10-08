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
ll a[100],n;
void dfs(int step){
    if(step==2*n+1){
        ll L,R;L=0,R=a[1]*a[2*n];
        for(int i=1;i<=2*n;i+=2){
            L+=a[i]*a[i+1];
        }
        for(int i=2;i<=2*n-2;i+=2){
            R*=(a[i]+a[i+1]);
        }
        if(L==R&&L){
            for(int i=1;i<=2*n;i++) cout<<a[i]<<" ";
            cout<<'\n';
        }
        return ;
    }
    for(int x=-2;x<=2;x++){
        if(x==0) continue;
        a[step]=x;
        dfs(step+1);
    }
}
void sol() {
    cin>>n;
    dfs(1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    // freopen("Dck.txt","w",stdout);
    while (t--) {
        sol();
    }
    return 0;
}