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
const ll mod=998244353;
const int N=3e5+10;
VL v;
ll n,m,l[N],r[N];
ll a[N],x[N],y[N],cnt[N];
void sol() {
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>x[i];
    for(int i=1;i<=m;i++) cin>>y[i];
    l[x[1]]=0;
    r[0]=x[1];
    a[x[1]]=x[1];
    for(int i=1;i<=m;i++){
        if(a[x[i]]){
            a[y[i]]=y[i];
            r[y[i]]=r[x[i]];
            l[y[i]]=x[i];
            l[r[x[i]]]=y[i];
            r[x[i]]=y[i];
        }else{
            a[x[i]]=x[i];
            r[x[i]]=y[i];
            l[x[i]]=l[y[i]];
            r[l[y[i]]]=x[i];
            l[y[i]]=x[i];
        }
    }
    for(int j=r[0];j;j=r[j]) v.push_back(j);
    cnt[v[0]]=1,cnt[v.back()]=1;
    for(int i=1;i<v.size();i++) cnt[max(v[i],v[i-1])]++;
    ll res=1,ans=0;
    for(int i=n;i>=1;i--){
        if(!a[i]){
            res=res*ans%mod;
            ans=(ans+1)%mod;
        }
        ans=(ans+cnt[i])%mod;
    }
    cout<<res<<'\n';
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