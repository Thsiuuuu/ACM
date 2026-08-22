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
    cin>>n>>k;
    string  s;cin>>s;
    k=min(n,k);
    if(n<=6){
        cout<<"0\n";
    }else{
        int ans=0;
        vector<bool> is(2*n+1,false);
        for(int i=0;i+6<n;i++){
            if(s.substr(i,7)=="nanjing") ans++,is[i]=true;
        }
        s=s+s;
        // cout<<s<<'\n';
        int tmp=ans;
        for(int i=1;i<=k;i++){
            if(is[i-1]) tmp--;
            if(s.substr(n+i-7,7)=="nanjing") is[i]=true,tmp++;
            ans=max(ans,tmp);
        }
        cout<<ans<<'\n';
    }
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