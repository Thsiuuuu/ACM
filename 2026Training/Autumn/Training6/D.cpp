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
    if(n==2){
        cout<<"1 -3 -3 1\n";
        return;
    }else if(n==3){
        cout<<"1 -10 6 6 -10 1\n";
        return ;
    }else if(n==4){
        cout<<"1 -15 10 -1 -1 10 -15 1\n";
        return ;
    }
    cout<<2*n-3<<" ";
    for(int i=2;i<2*n;i+=2){
        cout<<"2 -1 ";
    }
    cout<<1;
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