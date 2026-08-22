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
int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
void sol() {
    ll ans=0;
    string s;
    cin>>s;
    for(int k=0;k<26;k++){
        ll sum=0;
        for(int i=0;i<s.size();i++){
            char c=s[i]+k;
            if(c>'Z') c-=26;
            sum+=holes_cnt[c-'A'];
        }
        ans=max(ans,sum);
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