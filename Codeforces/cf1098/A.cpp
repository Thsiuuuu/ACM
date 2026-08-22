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
    ll ans=0;
    ll s1,s2;
    s1=s2=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int w;cin>>w;
        if(w==0) ans++;
        else if(w==1) s1++;
        else s2++;
    }
    ans+=min(s1,s2);
    int Mn=min(s1,s2);
    s1-=Mn,s2-=Mn;
    ans+=s1/3,ans+=s2/3;
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