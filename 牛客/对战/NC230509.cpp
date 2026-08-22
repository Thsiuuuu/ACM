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
ll ori[26],ans[26];
const ll mod=1e9+7;
void sol() {
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        ori[s[i]-'a']++;
        ans[s[i]-'a']++;
    }
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            ll k;
            cin>>k;
            for(int i=0;i<26;i++) ans[i]=(ans[i]+ori[i]*k%mod)%mod;
        }else{
            char c;
            cin>>c;
            cout<<ans[c-'a']<<'\n';
        }
    }
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