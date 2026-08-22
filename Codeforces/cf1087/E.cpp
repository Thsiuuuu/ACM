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

void prefix_function(const string&s,vector<ll>&pi){
    int n=s.size();
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
}

void sol() {
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    while(q--){
        int l,r;
        cin>>l>>r;
        string t=s.substr(l-1,r-l+1);
        int siz=r-l+1;
        vector<ll> pi(siz,0),f(siz,0),g(siz,0);
        prefix_function(t,pi);
        for(int i=1;i<siz;i++){
            if(pi[i]==0) g[i]=0;
            else if(pi[pi[i]-1]==0) g[i]=pi[i];
            else g[i]=g[pi[i]-1];
        }
        ll ans=0;
        for(int i=0;i<siz;i++){
            f[i]=f[i-g[i]]+1;
            ans+=f[i];
        }
        cout<<ans<<'\n';
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