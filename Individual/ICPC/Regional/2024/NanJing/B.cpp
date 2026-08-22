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
void sol() {
    string s;cin>>s;
    VI c(3,0);
    for(int i=0;i<s.size();i++){
        if(!(i&1)&&s[i]!='2') s[i]=('0'+('1'-s[i]));
    }
    for(int i=0;i<s.size();i++){
        c[s[i]-'0']++;
    }
    if(c[2]>=abs(c[0]-c[1])) cout<<(c[2]-abs(c[0]-c[1]))%2<<'\n';
    else cout<<(abs(c[0]-c[1])-c[2])<<'\n';
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