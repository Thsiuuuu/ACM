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
void prefix_function(const vector<ll>&s,vector<ll>&pi){
    int n=s.size();
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
}
ll KMP(const vector<ll> &text,const vector<ll>&pattern){
    ll res=0;
    vector<ll> cur=pattern;
    cur.push_back((ll)1e12);
    cur.insert(cur.end(),text.begin(),text.end());
    int sz1=text.size(),sz2=pattern.size();
    vector<ll> lps(sz1+sz2+1,0);
    prefix_function(cur,lps);//跑一遍前缀函数
    for(int i=sz2+1;i<=sz2+sz1;i++){
        if(lps[i]==sz2) res++;
    }
    return res;
}
void sol() {
    int n,w;
    cin>>n>>w;
    vector<ll> a(n),b(w);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<w;i++) cin>>b[i];
    if(w==1){
        cout<<n;
        return ;
    }
    vector<ll> text(n-1,0),pattern(w-1,0);
    for(int i=0;i<=w-2;i++) pattern[i]=b[i+1]-b[i];
    for(int i=0;i<=n-2;i++) text[i]=a[i+1]-a[i];
    // for(int i=0;i<=w-2;i++) cout<<text[i]<<" ";
    // cout<<'\n';
    // for(int i=0;i<=n-2;i++) cout<<pattern[i]<<" ";
    cout<<KMP(text,pattern);
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