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
ll a[N],ans[N],n,mx;
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        if(i==1||a[i-1]<a[i]) cnt++;
        if(i<n&&a[i]<a[i+1]) cnt--;
        int l=1,r,k;
        while(l<a[i]){
            k=(a[i]-1)/l,r=(a[i]-1)/k;
            ans[l]+=cnt*(k+1);
            ans[r+1]-=cnt*(k+1);
            l=r+1;
        }
        ans[a[i]]+=cnt;
        ans[mx+1]-=cnt;
    }
    for(int i=1;i<=mx;i++) ans[i]+=ans[i-1];
    for(int i=1;i<=mx;i++) cout<<ans[i]<<' ';
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