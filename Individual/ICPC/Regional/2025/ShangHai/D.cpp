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
int pw[16],a[1<<16],n,res=0,sum[43046722];
void dfs(int l,int r,int pos,int mask){
    if(pos==-1){
        sum[mask]=a[l];
        res^=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    dfs(l,mid,pos-1,mask);
    dfs(mid+1,r,pos-1,mask+pw[pos]);
    for(int i=mask;i<mask+pw[pos];i++){
        sum[i+2*pw[pos]]=sum[i]+sum[i+pw[pos]];
        res^=sum[i+2*pw[pos]];
    }
}
void sol() {
    cin>>n;
    for(int i=0;i<(1<<n);i++) cin>>a[i]; 
    pw[0]=1;
    for(int i=1;i<16;i++) pw[i]=pw[i-1]*3;
    dfs(0,(1<<n)-1,n-1,0);
    cout<<res;
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