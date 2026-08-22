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
    string s;
    cin>>s;
    int s1=0,s2=0;
    ll ans=0;
    for(int i=0;i<s.size();i++){
        if(s1+1<=s2){
            s1++;
            if(s[i]=='g') ans++;
        }else{
            s2++;
            if(s[i]=='p') ans--;
        }
    }
    cout<<ans;
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