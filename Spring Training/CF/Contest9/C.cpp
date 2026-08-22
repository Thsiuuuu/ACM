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
    int n;
    char c;
    while(cin>>n>>c){
        if(c=='R'){
            cout<<n<<'\n';
        }else if(c=='B'){
            cout<<n<<'\n';
        }else if(c=='N'){
            if(n<=2) cout<<"1\n";
            else cout<<"2\n";
        }else {
            if(n==1) cout<<"1\n";
            else cout<<"4\n";
        }
    }
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