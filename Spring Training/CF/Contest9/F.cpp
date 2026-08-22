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
    int n;
    while(cin>>n){
        vector<vector<ll>> f(n+1,vector<ll>(n+1,0));
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=0;i<n;i++) f[i][i+1]=(a[i]==a[i+1]);
        for(int len=3;len<=n;len++){
            for(int i=1;i<n;i++){
                int j=i+len-1;
                if(j>n) break;
                f[i][j]=max(f[i+1][j],f[i][j-1]);
                if(a[i]==a[j]) f[i][j]=max(f[i][j],1+f[i+1][j-1]);
            }
        }
        cout<<f[1][n]<<'\n';
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