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
int cnt[2],ans[200010];
void sol() {
    int n;string s;cin>>n>>s;
    cnt[0]=cnt[1]=0;
    if(2*count(s.begin(),s.end(),')')!=n){
        cout<<"-1\n";
        return ;
    }
    int tt=0,shift=0;
    for(int i=0;i<n;i++){
        if(!shift){
            if(s[i]=='(') cnt[0]++,ans[i]=1;
            else if(cnt[0]) cnt[0]--,ans[i]=1;
            else shift=1;
        }
        if(shift){
            if(s[i]==')') cnt[1]++,ans[i]=2;
            else if(cnt[1]) cnt[1]--,ans[i]=2;
            else shift=0;
        }
        if(!shift){
            if(s[i]=='(') cnt[0]++,ans[i]=1;
            else if(cnt[0]) cnt[0]--,ans[i]=1;
            else shift=1;
        }
    }
    cout<<(count(ans,ans+n,1)>0)+(count(ans,ans+n,2)>0)<<'\n';
    if(count(ans,ans+n,2)==n) for(int i=0;i<n;i++) ans[i]=1;
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<'\n';
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