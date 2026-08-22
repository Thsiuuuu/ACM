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
char mp[52][52];
int n,m,ans[52][52];
int dir[5]={-1,0,1,0,-1};
bool ck(int i,int j){
    return i>=0&&i<n&&j>=0&&j<m;
}
void sol() {
    cin>>n>>m;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin>>mp[i][j];
    //     }
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int dx=i+dir[k],dy=j+dir[k+1];
                ans[i][j]+=ck(dx,dy);
            }
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
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