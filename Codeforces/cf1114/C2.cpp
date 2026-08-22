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
    int n;string a,b;cin>>n>>a>>b;
    int u;u=0;
    ll ans=0;
    for(int i=0;i<n;i+=2){
        if(b[i]=='1'){
            while(u<n&&a[u]=='0') u+=2;
            if(u>=n){
                cout<<"-1\n";
                return ;
            }else{
                ans+=abs(u-i)/2;
            }
            u+=2;
        }
    }
    while(u<n){
        if(a[u]=='1'){
            cout<<"-1\n";
            return ;
        }
        u+=2;
    }
    u=1;
    for(int i=1;i<n;i+=2){
        if(b[i]=='1'){
            while(u<n&&a[u]=='0') u+=2;
            if(u>=n) {
                cout<<"-1\n";
                return ;
            }else{
                ans+=abs(u-i)/2;
            }
            u+=2;
        }
    }
    while(u<n){
        if(a[u]=='1'){
            cout<<"-1\n";
            return ;
        }
        u+=2;
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