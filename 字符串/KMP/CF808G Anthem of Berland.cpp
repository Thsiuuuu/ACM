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
    string s,t;
    cin>>s>>t;
    s=' '+s;
    int n=s.size(),m=t.size();
    vector<vector<ll>> f(n+1,vector<ll>(m+1,0));
    vector<ll> pi(m+1,0);
    prefix_function(t,pi);
    f[0][0]=0;
    for(int i=1;i<=m;i++) f[0][i]=-1;
    for(int i=1;i<n;i++){
        // cout<<i<<'\n';
        f[i][0]=*max_element(f[i-1].begin(),f[i-1].end());
        // cout<<f[i][0]<<" ";
        for(int j=0;j<m;j++){
            if((s[i]==t[j]||s[i]=='?')&&f[i-1][j]>=0){
                f[i][j+1]=f[i-1][j];
                if(i>=m&&j+1==m){
                    f[i][m]=f[i][m]+1;
                    int idx=m;
                    while(idx>0){
                        f[i][idx]=max(f[i][idx],f[i][m]);
                        idx=pi[idx-1];
                    }
                    f[i][0]=max(f[i][0],f[i][m]);
                }
            }else f[i][j+1]=-1;
            // cout<<f[i][j+1]<<" ";
        }
        // cout<<'\n';
    }
    // for(int i=1;i<n;i++){
    //     cout<<i<<" "<<"0\n";
    //     cout<<f[i][0]<<'\n';
    //     for(int j=0;j<m;j++){
    //         cout<<i<<" "<<j+1<<'\n';
    //         cout<<f[i][j+1]<<'\n';
    //     }
    // }
    cout<<*max_element(f[n-1].begin(),f[n-1].end());
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