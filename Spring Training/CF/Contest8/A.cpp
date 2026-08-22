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
    s=' '+s;
    int n=s.size();
    vector<int> all,pre(n,0),suf(n,INT32_MAX);
    for(int i=1;i<n;i++){
        if(s[i]=='s') all.push_back(i);
        pre[i]+=pre[i-1];
        pre[i]+=(s[i]=='y');
    }
    if(s[n-1]=='u') suf[n-1]=n-1;
    for(int i=n-2;i>=1;i--){
        suf[i]=suf[i+1];
        if(s[i]=='u') suf[i]=i;
    }
    if(all.size()<2){
        cout<<"0";
        return ;
    }
    ll ans=0,last=0;
    // for(int i=1;i<n;i++){
    //     cout<<i<<'\n';
    //     cout<<pre[i]<<" "<<suf[i]<<'\n';
    // }

    // cout<<n<<'\n';
    for(int i=0;i+1<all.size();i++){
        int x=all[i],y=all[i+1];
        // cout<<x<<" "<<y<<'\n';
        // cout<<suf[y]<<'\n';
        if(pre[y]-pre[x]>0&&suf[y]!=INT32_MAX){
            ans+=(ll)(x-last)*(n-suf[y]);
            last=x;
        }
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