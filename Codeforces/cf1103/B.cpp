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
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<n-k;i++){
        // cout<<s<<'\n';
        if(s[i]=='1') s[i]='0',s[i+k]=((s[i+k]=='1')?'0':'1');
    }
    cout<<((count(s.begin(),s.end(),'0')==n)?"yes\n":"no\n");
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