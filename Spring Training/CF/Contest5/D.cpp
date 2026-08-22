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
    int n;cin>>n;
    string s;cin>>s;
    if(s.size()==1){
        cout<<"0 0\n";
    }else{
        int ans1=0;
        ll ans2=0;
        string t=s;
        sort(t.begin(),t.end(),greater<char>());
        if(s[0]==t[1]&&s[n-1]==t[0]) ans1=0;
        else if(s[0]==t[1]||s[n-1]==t[0]||(s[0]==t[0]&&s[n-1]==t[1])) ans1=1;
        else ans1=2;
        for(int i=0;i<t.size();i++) ans2+=(11*(t[i]-'0'));
        ans2-=(t[1]-'0'+10*(t[0]-'0'));
        cout<<ans1<<" "<<ans2<<'\n';
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