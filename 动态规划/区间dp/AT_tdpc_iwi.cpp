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
const int N=310;
int f[N][N];
void sol() {
    string s;cin>>s;
    int n=s.size();
    for(int len=3;len<=n;len++){
        for(int i=0,j=i+len-1;j<n;i++,j++){
            for(int k=i+1;k<=j;k++) f[i][j]=max(f[i][j],f[i][k-1]+f[k][j]);
            if(s[i]=='i'&&s[j]=='i'){
                for(int k=i+1;k<=j-1;k++){
                    if(f[i+1][k-1]*3==(k-i-1)&&f[k+1][j-1]*3==(j-k-1)&&s[k]=='w') f[i][j]=len/3;
                }
            }
        }
    }
    cout<<f[0][n-1]<<'\n';
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