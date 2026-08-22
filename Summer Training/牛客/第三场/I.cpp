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
const int N=5e5+10;
ll a[N];
void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0,pr=-1e18;
    if(n==2){
        cout<<llabs(a[2]-a[1])<<'\n';
        return ;
    }
    auto c=[&](int i)->ll{
        return llabs(a[i]-a[i-1])+llabs(a[i]-a[i+1]);
    };
    for(int mask=0;mask<16;mask++){
        int s1=((mask>>0)&1)?1:-1;
        int s2=((mask>>1)&1)?1:-1;
        int s3=((mask>>2)&1)?1:-1;
        int s4=((mask>>3)&1)?1:-1;
        pr=-1e18;
        for(int i=2;i<=n-1;i++){
            ll B=s3*a[i-1]-s4*a[i+1]+(s2-s1)*a[i]-c(i);
            ans=max(ans,pr+B);
            if(i>=3){
                pr=max(pr,s1*a[i-2]-s2*a[i]+(s4-s3)*a[i-1]-c(i-1));
            }
        }
    }
    ans=max(ans,llabs(a[n-1]-a[1])+llabs(a[2]-a[n])-llabs(a[1]-a[2])-llabs(a[n]-a[n-1]));
    for(int i=2;i<=n-1;i++){
        if(i<=n-2)  ans=max(ans,llabs(a[i+1]-a[i-1])+llabs(a[i]-a[i+2])-llabs(a[i]-a[i-1])-llabs(a[i+2]-a[i+1])),ans=max(ans,llabs(a[i]-a[n-1])+llabs(a[n]-a[i-1])+llabs(a[n]-a[i+1])-llabs(a[n]-a[n-1])-llabs(a[i]-a[i-1])-llabs(a[i]-a[i+1]));
        if(i>=3) ans=max(ans,llabs(a[i]-a[2])+llabs(a[1]-a[i-1])+llabs(a[1]-a[i+1])-llabs(a[1]-a[2])-llabs(a[i]-a[i-1])-llabs(a[i]-a[i+1]));
    }
    
    ans=max(ans,llabs(a[1]-a[3])-llabs(a[3]-a[2]));
    ans=max(ans,llabs(a[n]-a[n-2])-llabs(a[n-1]-a[n-2]));
    for(int i=1;i<n;i++){
        ans+=llabs(a[i]-a[i+1]);
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