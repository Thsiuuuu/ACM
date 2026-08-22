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

void Z_function(const string&s,vector<int>&z){
    int n=(int)s.size();
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r&&z[i-l]<r-i+1){
            z[i]=z[i-l];
        }else{
            z[i]=max(0,r-i+1);
            while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) ++z[i];
        }
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
}
void sol() {
    string s;
    cin>>s;
    vector<int> z(s.size(),0);
    Z_function(s,z);
    map<int,int> mp;
    int n=s.size();
    vector<ll> pre(s.size()+1,0);
    // cout<<z[n-2]<<'\n';
    z[0]=s.size();
    for(int i=0;i<s.size();i++){
        if(i+z[i]==n) mp[z[i]]=0;
        pre[z[i]]++;
    }
    for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
    cout<<mp.size()<<'\n';
    for(auto &[key,val]:mp){
        val=pre[n]-pre[key-1];
        cout<<key<<" "<<val<<'\n';
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