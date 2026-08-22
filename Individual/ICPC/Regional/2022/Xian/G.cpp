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
bool cmp(const string&a,const string&b){
    return a.size()<b.size();
}
void sol() {
    string s;int n;
    map<string,bool> mp;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<a.size();i++){
        if(a[i].size()==1) mp[a[i]]=1;
        else{
            mp[a[i]]=(mp[a[i].substr(0,a[i].size()-1)]&&mp[a[i].substr(1,a[i].size()-1)]);
        }
    }
    for(int i=a.size()-1;i>=0;i--){
        if(mp[a[i]]){
            cout<<a[i].size()<<'\n';
            return ;
        }
    }
    cout<<"0\n";
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