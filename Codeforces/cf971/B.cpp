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
char mp[510][8];
void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=4;j++){
            if(mp[i][j]=='#'){
                cout<<j<<" ";
                break;
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