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
const string tem="execute";
void sol() {
    string s;
    cin>>s;
    // ll ans=0;
    for(int i=0;i+6<s.size();i++){
        if(s.substr(i,7)==tem){
            int len=1;
            int j=i+6;
            while(j+6<s.size()&&s.substr(j,7)==tem){
                // s[j]='1';
                j=j+6;
                len++;
            }
            int cl=1;
            int k=i;
            while(cl<=len){
                if(len&1){
                    if(cl&1) s[k]='1';
                }else{
                    if(!(cl&1)) s[k]='1';
                }
                cl++;
                k+=6;
            }
            i=j;
        }
    }
    cout<<s<<'\n';
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