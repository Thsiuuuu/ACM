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
const int N=1e5+10;
ll a[N];
void sol() {
    int n;cin>>n;
    ll xr=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xr^=a[i];
    }
    if(!xr) cout<<"DRAW\n";
    else{
        int idx;
        for(int i=32;i>=0;i--){
            if((xr>>i)&1){
                idx=i;
                break;
            }
        }
        ll s=0;
        for(int i=1;i<=n;i++){
            if((a[i]>>idx)&1){
                s++;
            }
        }
        if((s-1)%4==0){
            cout<<"WIN\n";
        }else{
            if((n-s)&1){
                cout<<"WIN\n";
            }else{
                cout<<"LOSE\n";
            }
        }
    }
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