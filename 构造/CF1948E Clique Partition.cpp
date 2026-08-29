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
void sol() {
    int n,k;cin>>n>>k;
    VI ans(n+1);
    int l=1,r;
    int tt=0;
    for(;l<=n;l=r+1){
        r=min(l+k-1,n);
        int mid=(l+r)>>1;
        for(int i=mid+1;i<=r;i++) ans[i]=++tt;
        for(int i=l;i<=mid;i++) ans[i]=++tt;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<'\n'; 
    cout<<(n+k-1)/k<<'\n';
    for(int i=1,num=0;i<=n;i++){
        num+=((i-1)%k==0);
        cout<<num<<" ";
    }
    cout<<'\n';
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