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
    if(s.size()==2){
        if(s[0]!=s[1]) cout<<"-1 -1";
        else cout<<"1 2";
    }else{
        for(int i=0;i<=s.size()-3;i++){
            if(s[i]==s[i+1]||s[i+1]==s[i+2]||s[i]==s[i+2]){
                cout<<i+1<<' '<<i+3;
                return ;
            }
        }
        cout<<"-1 -1";
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