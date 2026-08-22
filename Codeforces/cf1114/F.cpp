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
void sol(){
    int n;cin>>n;
    VL a(n),b(n);
    ll sa,sb;sa=sb=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sa^=a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        sb^=b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a==b){
        cout<<"YES\n";
        return ;
    }
    ll x=sa^sb;
    bool f=true;
    if(find(a.begin(),a.end(),x)==a.end()){
        cout<<"NO\n";
        return ;
    }
    for(int i=0;i<n;i++){
        if(f&&a[i]==x) f=false;
        else{
            a[i]^=x;
        }
    }
    sort(a.begin(),a.end());
    if(a==b){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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