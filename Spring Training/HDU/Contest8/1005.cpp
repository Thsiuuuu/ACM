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
    ll ans=0;
    vector<int> a(2,0);
    int num=0;
    for(int l=0,r=-1;l<s.size();l++){
        while(r+1<s.size()){
            if(num==1&&a[s[r+1]-'0']==0) break;
            if(++a[s[r+1]-'0']==1) num++;
            r++;
        }
        // cout<<r<<'\n';
        ans+=(2*(s.size()-r-1));
        if(s[r]=='0') ans+=(r-l+1);
        if(--a[s[l]-'0']==0) num--;
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