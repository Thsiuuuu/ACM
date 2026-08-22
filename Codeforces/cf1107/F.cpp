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
    int n;string s;cin>>n>>s;
    bool f=true;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') cnt++;
        if(s[i]=='0'&&cnt){
            int j=i;
            while(j<n&&s[j]=='0') j++;
            if(cnt&1){
                f=false;break;
            }
            else f&=(!((j-i)&1)),cnt=0;
            i=j-1;
        }
    }
    cout<<(f?"Bob\n":"Alice\n");
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