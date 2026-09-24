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
const int N=2e5+10;
ll pre[N],suf[N];
int n;
string s;
void sol() {
    cin>>n>>s;
    s=' '+s;
    for(int i=0;i<=n+1;i++) pre[i]=suf[i]=0;
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='1');
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+(s[i]=='0');
    bool is=false;
    ll ans=1e18;
    if(s[1]=='1') ans=count(s.begin()+1,s.end(),'0');
    else{
        for(int i=1;i<=n;i++){
            if(s[i]=='1'){
                is=true;
                ans=min(ans,pre[i-1]+suf[i+1]+(s[i]=='0'));
            }else if(is){
                ans=min(ans,pre[i-1]+suf[i+1]+(s[i]=='0'));
            }
        }
    }
    if(s[1]!='1'){
        ans=min(ans,1ll*count(s.begin()+1,s.end(),'1'));
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