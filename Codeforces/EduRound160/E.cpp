#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>



正解是费用流，哈哈没学过，现学了一下，想看代码去图论/网络流/费用流里面看吧
2026.9.4 14:05
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
const int N=52;
int a[N][N],A[N],B[N],row[N],col[N];
void sol() {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=m;i++) cin>>B[i];
    int rs,cs;rs=cs=0;
    for(int i=1;i<=n;i++)rs+=A[i];
    for(int i=1;i<=m;i++) cs+=B[i];
    if(rs^cs){
        cout<<"-1\n";
        return ;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            row[i]+=a[i][j];
            col[j]+=a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(row[i]<A{i}&&col[j]<B[j]&&!a[i][j]) row[i]+=1,col[j]+=1,ans++,++a[i][j];
            if(row[i]>A[i]&&col[j]>B[j]&&a[i][j]) row[i]--,col[j]--,ans--,a[i][j]--; 
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
        }
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