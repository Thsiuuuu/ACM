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

const ld PI=acos(-1);

const ld t=220,m=4;

ld Fun(ld k){
    // cout<<k<<" ";
    // cout<<k*sin(2*PI/k)<<'\n';

    return k*tan(PI/k);

}


void TestForIdontKnowAwAQwq(){
    int Mxidx=3;
    ld Mx=0;
    
    for(int k=3;k<=t/m;k++){
        cout<<k<<" ";
        cout<<pow(t-k*m,2)/(k*tan(PI/k))<<'\n';
        if(pow(t-k*m,2)/(k*tan(PI/k))>Mx) Mxidx=k,Mx=pow(t-k*m,2)/(k*tan(PI/k));
    }
    cout<<Mxidx<<" "<<Mx<<'\n';
}


void sol() {
    TestForIdontKnowAwAQwq();
    // Fun(4);
    // Fun(1145140101010119191);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}