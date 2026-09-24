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
const int N=1e6+10;
int a[N],n,lmax[N],rmax[N],lmin[N],rmin[N];
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=a[n+1]=n+1;
    stack<int> stk;
    stk.push(0);
    for(int i=1;i<=n+1;i++){
        while(stk.size()&&a[stk.top()]<a[i]){
            rmax[stk.top()]=i;
            stk.pop();
        }
        lmax[i]=stk.top();
        stk.push(i);
    }
    while(stk.size()) stk.pop();
    a[0]=a[n+1]=0;
    stk.push(0);
    for(int i=1;i<=n+1;i++){
        while(stk.size()&&a[stk.top()]>a[i]){
            rmin[stk.top()]=i;
            stk.pop();
        }
        lmin[i]=stk.top();
        stk.push(i);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        int L=lmax[i],R=rmax[i];
        ans+=i-L-1;
        if(i-L<=R-i){
            int pos=i,rp=rmin[pos];
            for(int j=i-1;j>L;j--){
                if(a[j]<a[pos]) pos=j;
                rp=rmin[pos];
                ans+=min(rp-i,R-i)-1;
            }
        }else{
            int pos=i,lp=lmin[pos];
            for(int j=i+1;j<R;j++){
                if(a[j]<a[pos]) pos=j;
                lp=lmin[pos];
                ans+=max(lp-L,0);
            }
        }
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