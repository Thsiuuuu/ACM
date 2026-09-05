#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
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
const int N=1e6+10;
int n,R[N];
void sol() {
    string t;cin>>n>>t;
    for(int i=0;i<n;i++){
        if(i&1) t[i]=((t[i]=='1')?'0':'1');
    }
    string s="#";
    for(auto c:t) s+=c,s+='#';
    n=s.size();
    for(int i=0,r=0,len,c;i<n;i++){
        len=i<r?min(r-i,R[c*2-i]):0;
        while(i-len>=0&&i+len<n&&(s[i-len]==s[i+len])) len++;
        R[i]=len-1;
        if(i+len>r){
            r=i+len;
            c=i;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='#') ans+=R[i]/2;
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