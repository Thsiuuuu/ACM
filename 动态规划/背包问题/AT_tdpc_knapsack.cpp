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

ll f[52][10003];
ll tmp[10003];
vector<pii> p[51];
int n,W,C;
void sol() {
    cin>>n>>W>>C;
    for(int i=0;i<n;i++){
        int w,v,c;cin>>w>>v>>c;
        p[c].push_back({w,v});
    }
    for(int c=1;c<=50;c++){
        if(p[c].empty()) continue;
        for(int i=C;i>=1;i--){
            for(int j=0;j<=10000;j++) tmp[j]=f[i-1][j];
            for(const auto&[w,v]:p[c]){
                for(int j=10000;j>=w;j--){
                    tmp[j]=max(tmp[j-w]+v,tmp[j]);
                }  
            }
            for(int j=0;j<=10000;j++) f[i][j]=max(f[i][j],tmp[j]);
        }
    }
    cout<<*max_element(f[C],f[C]+W+1)<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // auto start=chrono::steady_clock::now();  
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    // auto end=chrono::steady_clock::now();
    // cout<<chrono::duration<double,milli>(end-start).count();
    return 0;
}