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
void sol() {
    string s;
    cin>>s;
    if(s.size()<5){
        cout<<"No\n";
        return ;
    }
    s=' '+s;
    string res(s.size(),'-');
    int len=s.size();
    if(s.substr(len-3,3)!=">>>"){
        cout<<"No\n";
        return ;
    }
    if(count(s.begin(),s.end(),'>')==len-1){
        cout<<"No\n";
        return ;
    }
    int last=0;
    for(int i=len-1;i>=1&&s[i]=='>';last=i--);
    vector<pii> all;
    for(int i=len-1;i-2>=last;i--){
        all.push_back({1,i});
        res[i]=res[i-1]=res[i-2]='>';
    }
    res[1]='>';
    for(int i=2;i<last;i++){
        if(s[i]=='>'){
            all.push_back({i,last-i+3});
            res[i]='>'; 
        }
    }
    for(int i=1;i<len;i++){
        if(s[i]!=res[i]){
            cout<<"No\n";
            return ;
        }
    }
    cout<<"Yes "<<all.size()<<'\n';
    for(const auto&[key,val]:all){
        cout<<key<<" "<<val<<'\n';
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