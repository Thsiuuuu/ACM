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
    bool f=false;
    ll ans=0;
    string s;
    cin>>s;
    int idx=-1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='2'){
            idx=i;
            break;
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='4') ans++;
    }
    if(idx==-1){
        cout<<ans<<'\n';
        return ;
    }
    vector<ll> suf(s.size(),0);
    for(int i=s.size()-1;i>=0;i--){
        if(i!=s.size()-1) suf[i]+=suf[i+1];
        suf[i]+=(s[i]=='2');
    }
    ll sum=INT64_MAX;
    ll rem=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='4') continue;
        if(s[i]!='2'){
            sum=min(sum,rem+suf[i]);
            rem++;
        }
    }
    if(sum==INT64_MAX) sum=0;
    sum=min(sum,rem);
    ans+=sum;
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