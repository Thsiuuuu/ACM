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
const ll mod=1e9+7;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
ll pw2,pw3,pw6;
ll cal(ll x,ll y){
    return ((x*x%mod*x%mod+y*y%mod*y%mod)%mod-(llabs(x-y)*llabs(x-y)%mod*llabs(x-y)%mod)+mod)%mod;
}
void sol() {
    int n;
    cin>>n;
    vector<pll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    ll ans=0;
    for(int i=1;i<n;i++){
        auto [l1,r1]=a[i-1];
        auto [l2,r2]=a[i];
        if(r1==l1&&r2==l2) ans=(ans+llabs(r1-r2))%mod;
        else if(r1>l1&&r2>l2){
            ll I=(((cal(r1,r2)-cal(r1,l2)+mod)%mod-cal(l1,r2)+mod)%mod+cal(l1,l2))%mod*pw6%mod;
            ll de=(r2-l2)*(r1-l1)%mod;
            ans=(ans+I*ksm(de,mod-2)%mod)%mod;
        }else{
            if(r2==l2){
                swap(l1,l2),swap(r1,r2);
            }
            if(l1<=l2) ans=(ans+((r2+l2)%mod*pw2%mod-l1+mod)%mod)%mod;
            else if(l1>=r2) ans=(ans-((r2+l2)%mod*pw2%mod-l1+mod)%mod+mod)%mod;
            else{
                ll de=2*(r2-l2+mod)%mod;
                de=ksm(de,mod-2);
                ans=(ans+((l1-l2+mod)%mod*((l1-l2+mod)%mod)%mod+(l1-r2+mod)%mod*((l1-r2+mod)%mod)%mod)%mod*de%mod)%mod;
            }
        }
        // if(a[i].first==a[i-1].first&&a[i].second==a[i-1].second){
           
        // }else{
        //     ll minR=min(r1,r2),
        //        maxR=max(r1,r2),
        //        minL=min(l1,l2),
        //        maxL=max(l1,l2);
        //        if(minR<=maxL){
        //             ans=(ans+(maxR+maxL-minR-minL+mod)%mod*pw2%mod)%mod;
        //        }else{
        //             ans=(ans+(maxR-maxL+1+mod)%mod*pw3%mod+(maxL+minL)%mod*pw2%mod-(maxR+minR)%mod*pw2%mod+mod)%mod;
        //        }
        // }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    pw2=ksm(2,mod-2);
    pw3=ksm(3,mod-2);
    pw6=ksm(6,mod-2);
    while (t--) {
        sol();
    }
    return 0;
}