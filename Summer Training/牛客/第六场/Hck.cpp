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
    VL a(n);
    iota(a.begin(),a.end(),1);
    do{
        if(a[0]!=1){
            break;
        }
        for(int i=0;i<n;i++){
            bool f=false;
            ll sum=abs(a[i]-a[(i+1)%n]);
            if(sum==1) continue;
            else{
                for(ll x=2;x*x<=n;x++){
                    if(sum%x==0){
                        f=true;
                        break;
                    }
                }
            }
            if(!f){
                cout<<"-1\n";
                return ;
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        return ;
    }while(next_permutation(a.begin(),a.end()));
    cout<<"-1\n";
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