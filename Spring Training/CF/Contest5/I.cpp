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

const int MaxH=32;
ll f[MaxH][2];

void init(){
    for(int i=1;i<=MaxH;i++){
        f[i][0]=f[i-1][1]+(1<<(i-1));
        f[i][1]=f[i-1][0];
    }
}

//要记录当前是第几位，
ll dfs(){
    
}

void sol() {
    int n;
    cin>>n;
    ll ans=0;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;

    init();
    while (t--) {
        sol();
    }
    return 0;
}