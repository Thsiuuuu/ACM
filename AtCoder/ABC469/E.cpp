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
const ld eps=1e-8;
int n,k;
string s;
bool ck(ld mid){
    vector<ld> f(n+1,0);
    vector<int> pr(n+1,0);
    for(int i=1;i<=n;i++){
        pr[i]=pr[i-1]+(s[i]=='o');
        f[i]=pr[i]-mid*i;
    }
    int cr=0;
    ld mn=pr[0];
    for(int i=1;i<=n;i++){
        while(cr+1<=n&&pr[cr+1]<=pr[i]-k){
            cr++;
            mn=min(f[cr],mn);
        }
        if(mn<=f[i]&&pr[cr]<=pr[i]-k){
            return true;
        }
    }
    return false;
}
void sol() {
    cin>>n>>k>>s;
    s=' '+s;
    ld l=0,r=1,ans,mid;
    while(l+eps<=r){
        mid=(l+r)/2;
        if(ck(mid)){
            ans=mid;
            l=mid;
        }else r=mid;
    }
    cout<<fixed<<setprecision(6)<<ans;
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