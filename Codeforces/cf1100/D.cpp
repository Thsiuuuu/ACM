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
ll cal(ll x,ll mid){
    return x>=mid?1:0;
}
void sol() {
    int n;
    cin>>n;
    VI a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    ll l=1,r=2e5,mid;
    ll ans;
    while(l<=r){
        mid=(l+r)>>1;
        ll sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            if(cal(a[i],mid)+cal(b[i],mid)==2){
                sum1++;
                continue;
            }
            int j=i;
            bool f=false;
            while(j<n&&cal(a[j],mid)+cal(b[j],mid)!=2){
                int fa=cal(a[j],mid),fb=cal(b[j],mid);
                if(fa==fb&&!f){
                    f=true;
                    sum2++;
                }
                j++;
            }
            i=j-1;
        }
        if(sum1>sum2){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<'\n';
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