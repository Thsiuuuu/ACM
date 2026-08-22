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

const ll mod=998244353;
void prefix_function(const vector<ll>&s,vector<ll>&pi){
    int n=s.size();
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
}

void sol() {
    int n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<ll>> pi(n+1);
    vector<ll> f(n+1,0);
    for(int l=1;l<=n;l++){
        vector<ll> s;
        for(int i=l;i<=n;i++){
            s.push_back(a[i]);
        }
        // cout<<s.size()<<'\n';
        pi[l].assign(s.size(),0);
        prefix_function(s,pi[l]);
        // for(int i=0;i<pi[l].size();i++){
        //     cout<<pi[l][i]<<" ";
        // }
        // cout<<'\n';
    }
    // for(int l=1;l<=n;l++){
    //     cout<<l<<" ";
    //     cout<<pi[l].size()-1<<'\n';
    // }
    f[0]=1;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=j;i++){
            if(!pi[i][j-i]) f[j]=(f[j]+f[i-1])%mod;
        }
    }
    cout<<f[n]<<'\n';
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