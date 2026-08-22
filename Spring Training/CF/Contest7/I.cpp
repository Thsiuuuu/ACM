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
void sol() {
    ull n;cin>>n;
    int i=1;
    while(i<=32){
        if((1ull<<i)-1>=n){
            cout<<i<<" bit";
            if(i^1) cout<<"s";
            cout<<'\n';
            return ;
        }
        i*=2;
    }
    cout<<"64 bits\n";
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