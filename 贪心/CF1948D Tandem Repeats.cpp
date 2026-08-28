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
bool ck(char a,char b){
    if(a=='?'||b=='?') return true;
    else return a==b;
}
void sol() {
    string s;cin>>s;
    int n=s.size();
    for(int d=(n>>1);d;d--){
        int cnt=0;
        for(int i=0;i<d;i++) cnt+=ck(s[i],s[i+d]);
        if(cnt==d){
            cout<<(d<<1)<<'\n';
            return ;
        }
        for(int i=d;i+d<n;i++){
            cnt-=ck(s[i],s[i-d]);
            cnt+=ck(s[i],s[i+d]);
            if(cnt==d){
                cout<<(d<<1)<<'\n';
                return ;
            }
        }
    }
    cout<<"0\n";
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