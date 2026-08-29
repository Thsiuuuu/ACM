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
    int n;cin>>n;
    VL a(n+3,0),pre,suf,lis,ris;pre=suf=ris=lis=a;
    lis[1]=ris[n]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        if(a[i]==a[i-1]) lis[i]=lis[i-1]+1;
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1]+a[i];
        if(a[i]==a[i+1]) ris[i]=ris[i+1]+1;
    }
    for(int i=1;i<=n;i++){
        ll ans=1e18;
        ll l=1,r=i-1,mid,res=-1;
        if(i>1){
            if(a[i-1]>a[i]) ans=1;
            else{
                l+=lis[i-1]+1;
                while(l<=r){
                    mid=(l+r)>>1;
                    if(pre[i-1]-pre[i-mid-1]>a[i]) res=mid,r=mid-1;
                    else l=mid+1;
                }
                ans=min(ans,res);
            }
        }
        if(i<n){
            if(a[i+1]>a[i]) ans=1;
            else{
                l=1,r=n-i,res=-1;
                l+=ris[i+1]+1;
                while(l<=r){
                    mid=(l+r)>>1;
                    if(suf[i+1]-suf[i+mid+1]>a[i]) res=mid,r=mid-1;
                    else l=mid+1;
                }
                if((ans==-1||ans==1e18)&&res==-1) ans=-1;
                else if(res!=-1) ans=((ans==-1||ans==1e18)?res:min(ans,res));
            }
        }
        if(n==1) ans=-1;
        cout<<ans<<" ";
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