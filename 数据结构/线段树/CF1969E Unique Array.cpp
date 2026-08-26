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
const int MAXN=3e5+10;
int T,n,ans,a[MAXN],last[MAXN],l[MAXN];
int cov[MAXN*4],sum[MAXN*4];
void upd(int L,int R,int k,int i,int l,int r){
	int mid=(l+r)>>1;
	if(l==L&&R==r) cov[i]+=k;
	else{
		if(L<=mid) upd(L,min(R,mid),k,i*2,l,mid);
		if(R>mid) upd(max(L,mid+1),R,k,i*2+1,mid+1,r);
	}
	if(cov[i]>0) sum[i]=r-l+1;
	else if(l<r) sum[i]=sum[i*2]+sum[i*2+1];
	else sum[i]=0;
}
void sol() {
    cin>>n;
    ans=0,memset(last,0,sizeof(last[0])*(n+5)),memset(l,0,sizeof(l[0])*(n+5));
    memset(cov,0,sizeof(cov[0])*(n+5)*4),memset(sum,0,sizeof(sum[0])*(n+5)*4);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[i]=last[a[i]]+1;
        upd(l[i],i,1,1,1,n); 
        if(last[a[i]]) upd(l[last[a[i]]],last[a[i]],-1,1,1,n);
        if(sum[1]<i) ans++,upd(1,i,1,1,1,n); 
        last[a[i]]=i; 
    }
    cout<<ans<<"\n";
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