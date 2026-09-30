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
const int N=2e5+10;
int n,m,k,pre[N],f[N][6][2];
string s;
bool ck(int len){
    for(int i=0;i<n+1;i++) for(int j=0;j<6;j++) f[i][j][0]=f[i][j][1]=1e9;
    f[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<6;j++){
            if(s[i]=='0'){
                f[i][j][0]=min({f[i-1][j][0],f[i][j][0],f[i-1][j][1]});
                f[i][j][1]=min(f[i][j][1],f[i-1][j][1]+1);
            }else{
                f[i][j][0]=min(f[i][j][0],f[i-1][j][0]);
                f[i][j][1]=min(f[i][j][1],f[i-1][j][1]);    
            }
            if(i>=len&&j) f[i][j][1]=min(f[i-len][j-1][0]+pre[i]-pre[i-len],f[i][j][1]);
        }
    }
    int mn=1e9;
    for(int i=1;i<=n;i++) mn=min({f[i][k][0],f[i][k][1],mn});
    // for(int i=1;i<=n;i++) for(int j=0;j<6;j++) cout<<f[i][j][0]<<" "<<f[i][j][1]<<'\n';
    // cout<<"*********\n";
    // cout<<min(f[n][m][0],f[n][m][1])<<'\n';
    // cout<<(mn<=m)<<'\n';
    return mn<=m;
}
void sol() {
    cin>>n>>m>>k;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='0');
    // for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
    // cout<<'\n';
    int l=1,ans=-1,r=n,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(ck(mid)){
            ans=mid,l=mid+1;
        }else r=mid-1;
    }
    cout<<ans;
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