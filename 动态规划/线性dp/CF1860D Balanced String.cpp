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
int f[2][103][6000];
void sol() {
    string s;cin>>s;
    s=' '+s;
    int n=s.size();
    for(int cnt=0;cnt<103;cnt++) for(int sum=0;sum<6000;sum++) f[0][cnt][sum]=f[1][cnt][sum]=1e9;
    f[0][0][0]=0;
    for(int i=1;i<n;i++){
        for(int cnt=i;cnt>=0;cnt--){
            for(int sum=5500;sum>=0;sum--){
                f[1][cnt][sum+cnt]=min(f[1][cnt][sum+cnt],f[0][cnt][sum]+(s[i]^'1'));
                f[1][cnt+1][sum]=min(f[1][cnt+1][sum],f[0][cnt][sum]+(s[i]^'0'));
            }
        }
        swap(f[1],f[0]);
        for(int cnt=0;cnt<103;cnt++) for(int sum=0;sum<6000;sum++) f[1][cnt][sum]=1e9;
    }
    int siz=count(s.begin()+1,s.end(),'0');
    cout<<f[0][siz][siz*(n-1-siz)/2]/2;
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