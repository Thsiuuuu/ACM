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
const int N=4e6+10;
int n,a[N];
pii f[1<<22];
void ck(pii&A, pii B){
    if(A.first<B.first){
        A.second=max(A.first,B.second);
        A.first=B.first;
    }else if(A.first==B.first){
        A.second=max(A.second,B.second);
    }else{
        A.second=max(A.second,B.first);
    }
}
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(i>f[a[i]].first) f[a[i]].second=f[a[i]].first,f[a[i]].first=i;
        else if(i>f[a[i]].second) f[a[i]].second=i;
    }
    for(int i=0;i<22;i++){
        for(int mask=(1<<22)-1;~mask;mask--){
            if(!((mask>>i)&1)) ck(f[mask],f[mask|(1<<i)]);
        }
    }
    int ans=0;
    for(int i=1;i<=n-2;i++){
        int x=0;
        for(int j=21;~j;j--){
            if((a[i]>>j)&1) continue;
            if(f[x|(1<<j)].second>i) x|=(1<<j);
        }
        ans=max(ans,x|a[i]);
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