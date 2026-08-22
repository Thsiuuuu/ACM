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
struct node{
    int idx=0;
    // int len;
    int mn=-1;
    int mx=-1;
    node(){}  
    node(int idx,
        // int len,
        int mn,int mx):idx(idx),
        // len(len),
        mn(mn),mx(mx){}
};
bool check(vector<vector<node>> &all,ll mid,int n){
    for(int i=0;i<n;i++){
        auto&[id1,mn1,mx1]=all[i][mid];
        if(mn1==-1) continue;
        for(int j=id1+mid;j<n;j++){
            auto&[id2,mn2,mx2]=all[j][mid];
            if(mn2==-1) continue;
            if(mx1+1==mn2||mx2+1==mn1) return true;
        }
    }
    return false;
}
void sol() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    VLL all(n+1,VL(n+1,-1));
    ll ans=0;
    for(int i=0;i<n;i++){
        vector<ll> cnt(n+1,0);
        ll l=a[i],r=a[i],Mx=a[i],Mn=a[i];
        for(int j=i;j<n;j++){
            if(cnt[a[j]]) break;
            else{
                cnt[a[j]]++;
                Mx=max(Mx,a[j]),Mn=min(Mn,a[j]);
                while(l-1>=1&&cnt[l-1]) l--;
                while(r+1<=n&&cnt[r+1]) r++;
                if(Mx-Mn+1==j-i+1){
                    if(all[j-i+1][Mn]==-1) all[j-i+1][Mn]=i;
                    if(Mx+1+j-i<=n&&all[j-i+1][Mx+1]!=-1&&i-all[j-i+1][Mx+1]>=j-i+1) ans=max(ans,(ll)j-i+1);
                    if(Mn-(j-i+1)>=1&&all[j-i+1][Mn-(r-l+1)]!=-1&&i-all[j-i+1][Mn-(r-l+1)]>=j-i+1) ans=max(ans,(ll)j-i+1);
                }
            }
        }
    }
    cout<<ans<<'\n';
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         auto&[id,mn,mx]=all[i][j];
    //         cout<<id<<" "<<mn<<" "<<mx<<'\n';
    //     }
    // }
    // ll l=0,r=n/2+1,mid,ans=0;
    // while(l<=r){
    //     mid=(l+r)>>1;
    //     // cout<<mid<<'\n';
    //     if(check(all,mid,n)){
    //         ans=mid;
    //         l=mid+1;
    //     }else{
    //         r=mid-1;
    //     }
    // }
    // cout<<ans<<'\n';
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