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
    ll x;cin>>x;
    VI ans;
    bool is=true;
    for(int i=63;i>=0;i--){
        if((x>>i)&1){
            if(is){
                is=false;
                for(int j=1;j<=i;j++) ans.push_back(j);
            }else{
                ans.push_back(i+1);
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(int x:ans) cout<<x<<" ";
    cout<<'\n';
    // VL f(ans.size(),0);
    // ll res=1;
    // for(int i=0;i<f.size();i++){
    //     for(int j=0;j<i;j++){
    //         if(ans[j]<ans[i]){
    //             f[i]+=f[j];
    //         }
    //     }
    //     f[i]+=1;
    //     res+=f[i];
    // }
    // for(int x:f) cout<<x<<" ";
    // cout<<'\n';
    // cout<<res<<'\n';
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