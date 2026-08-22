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
// 0阴，1晴
void sol() {
    int n;
    string  s;cin>>n>>s;
    s=' '+s;
    VL x(n+1),y(n+1);
    VLL f(n+1,VL(2,0));
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<n;i++) cin>>y[i];
    for(int i=1;i<=n;i++){
        if(i==1){
            f[1][0]=f[1][1]=-1e8;
            if(s[i]=='S') f[1][1]=0;
            else f[1][0]=0;
        }else{
            
        }
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