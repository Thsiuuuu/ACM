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
void sol() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    ll ans,idx;
    ans=idx=0;
    bool f=false;
    int Mx=0;
    int l=0;
    for(int r=0;r<n;r++){
        if(!f){
            if(min(a[r],b[r])==1&&a[r]!=b[r]){
                ans+=(r-idx)*(r-idx);
                // idx=r+1;
            }
            if(a[r]==b[r]&&a[r]==1){
                f=true;
                Mx=1;
                l=idx;
                idx=r;
            }
        }else{
            if(a[r]==b[r]||(max(a[r],b[r]))<=Mx){
                if(a[r]==Mx+1){
                    Mx++;
                }
                if(a[r]==1){
                    idx=r;
                }
            }else{
                f=false;
                ans+=(r-l)*(r-l);
            }
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