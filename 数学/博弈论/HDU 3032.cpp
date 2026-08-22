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

// const int N=1e3+1;
// int sg[N];
// void see(){
//     for(int x=1;x<N;x++){
//         set<int> s;
//         for(int i=0;i<x;i++){
//             s.insert(sg[i]);
//         }
//         for(int i=1;i<x;i++){
//             s.insert(sg[i]^sg[x-i]);
//         }
//         for(int i=0;;i++){
//             if(s.find(i)==s.end()){
//                 sg[x]=i;
//                 break;
//             }
//         }
//         cout<<x<<" "<<sg[x]<<'\n';
//     }
// }
void sol() {
    int n;
    cin>>n;
    ll xr=0;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        if((x+1)%4==0) xr^=(x+1);
        else if(x%4==0) xr^=(x-1);
        else xr^=x;
    }
    cout<<(xr?"Alice\n":"Bob\n");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    // see();
    while (t--) {
        sol();
    }
    return 0;
}