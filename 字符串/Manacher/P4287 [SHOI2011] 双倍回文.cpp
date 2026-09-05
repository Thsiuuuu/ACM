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
const int N=1000010;
int R[N];
void Manacher(const string&t){
    string s="#";
    int ans=0;
    for(auto c:t) s+=c,s+='#';
    int n=s.size();
    for(int i=0,r=0,len,c;i<n;i++){
        len=i<r?min(r-i,R[c*2-i]):0;
        while(i-len>=0&&i+len<n&&s[i-len]==s[i+len]){
            if(s[i]=='#'&&len%4==0){
                int mid=i-len/2;
                if(mid>=0&&R[mid]>=len/2) ans=max(ans,len);
            }
            len++;
        }
        R[i]=len-1;
        if(i+len>r){
            r=i+len;
            c=i;
        }
    }
    cout<<ans;  
}
void sol() {
    int n;
    string s;
    cin>>n>>s;
    Manacher(s);
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