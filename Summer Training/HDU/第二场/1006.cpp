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
const int N=1e6;
void sol() {
    int n;cin>>n;
    if(n<N){
        int s=n%1000,q=n/1000;
        for(int i=0;i<s;i++) cout<<'h';
        cout<<'d';
        for(int i=0;i<1000-s;i++) cout<<'h';
        for(int i=0;i<q;i++) cout<<'d';
        cout<<'u';
    }else if(n==(ll)(1e9)){
        for(int i=0;i<1000;i++) cout<<'h';
        for(int i=0;i<1000;i++) cout<<'d';
        for(int i=0;i<1000;i++) cout<<'u';
    }else{
        int s=n%1000;
        int q=(n-1001*s)/1000;
        for(int i=0;i<s;i++) cout<<'h';
        cout<<'d';
        for(int i=0;i<1000-s;i++) cout<<'h';
        int num=q/999;
        int rem=q%999;
        for(int i=0;i<999;i++){
            if(i==0){
                for(int cnt=0;cnt<1000-num;cnt++) cout<<'u';
            }
            if(i==rem) cout<<'u';
            cout<<'d';
            if(i==998){
                for(int cnt=0;cnt<num;cnt++) cout<<'u';
            }
        }
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