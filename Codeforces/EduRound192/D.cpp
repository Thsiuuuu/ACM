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
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
void sol() {
    string s,t;
    cin>>s>>t;
    s=' '+s,t=' '+t;
    int n=s.size(),m=t.size();
    VLL f(n,VL(m,0));
    VL a(n,0),b(m,0);
    for(int i=1;i<n;i++) a[i]=(a[i-1]+s[i]-'0')%10;
    for(int i=1;i<m;i++) b[i]=(b[i-1]+t[i]-'0')%10;
    if(a[n-1]!=b[m-1]){cout<<"-1\n";return ;}
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i]==b[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
            f[i][j]=max({f[i][j],f[i-1][j],f[i][j-1]});
        }
    }
    // if(f[n-1][m-1]==0) f[n-1][m-1]=-1;
    cout<<f[n-1][m-1]<<'\n';
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