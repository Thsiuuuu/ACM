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
    ll a,b;
    cin>>a>>b;
    ll Mn=min(a,b);
    if(Mn>1){
        cout<<"1\n";
        return ;
    }
    while(Mn<=(ll)(2e9)){
        if(Mn>min(a,b)&&Mn<max(a,b)){
            cout<<Mn<<'\n';
            return ;
        }
        Mn*=2;
    }
    cout<<a+b<<'\n';
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