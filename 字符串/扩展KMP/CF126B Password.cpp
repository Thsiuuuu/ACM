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
    string s,t;
    cin>>s;
    int n=s.size();
    if(n<=2){
        cout<<"Just a legend";
        return ;
    }
    vector<int> pre(n,0),suf(n,0);
    t=s;
    reverse(t.begin(),t.end());
    Z_function(s,pre);
    Z_function(t,suf);
    reverse(suf.begin(),suf.end());
    int idx=1,tmp=pre[idx];
    for(int i=1;i<n-1;i++){
        if(tmp<pre[i]){
            tmp=pre[i];
            idx=i;
        }
    }
    int mx=0;
    for(int len=1;len<=pre[idx];len++){
        int j=idx+len-1;
        if(j==n-1) break;
        if(len<=suf[j]) mx=max(mx,len);
    }
    if(mx==0){
        cout<<"Just a legend";
        return ;
    }
    for(int i=0;i<mx;i++){
        cout<<s[i];
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