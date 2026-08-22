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
const string mp="ania";
void sol() {
    string s;cin>>s;
    int ans=0;
    for(int i=0;i+3<s.size();i++){
        if(s.substr(i,4)==mp){
            int cnt=0;
            int j=i;
            while(j+3<s.size()&&s.substr(j,4)==mp){
                j+=3;
                cnt++;
            }
            ans+=(cnt+1)/2;
            i=j;
        }
    }
    cout<<ans<<'\n';
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