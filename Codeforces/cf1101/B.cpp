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
void sol() {
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<ll> ans(n+1);
    ans[1]=a[1];
    ll s=a[1];
    for(int i=2;i<=n;i++){
        ll r=ans[i-1],l=1,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(a[i]+s-(i-1)*mid>=mid){
                ans[i]=mid;
                l=mid+1;
            }else r=mid-1;
        }
        s+=a[i];
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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