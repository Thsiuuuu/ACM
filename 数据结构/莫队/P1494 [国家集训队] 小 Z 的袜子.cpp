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
const int N=5e4+10;
int blo[N];
ll cnt[N],B,n,m,c[N],sum;
struct node{
    int l,r,id;
    bool operator<(const node&o)const{
        return blo[l]!=blo[o.l]?l<o.l:((blo[l]&1)?r<o.r:r>o.r); 
    }
}Q[N],ans[N];
void add(int x){
    sum+=cnt[c[x]];
    cnt[c[x]]++;
}
void del(int x){
    cnt[c[x]]--;
    sum-=cnt[c[x]];
}
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
void sol() {
    cin>>n>>m;
    B=n/sqrt(m);
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) blo[i]=(i-1)/B;
    for(int i=0;i<m;i++){
        cin>>Q[i].l>>Q[i].r;
        Q[i].id=i;
    }
    sort(Q,Q+m);
    for(int i=0,l=1,r=0;i<m;i++){
        while(l>Q[i].l) add(--l);
        while(r>Q[i].r) del(r--);
        while(r<Q[i].r) add(++r);
        while(l<Q[i].l) del(l++);
        ll div=(Q[i].r-Q[i].l+1ll)*(Q[i].r-Q[i].l)/2,fac=1;
        if(sum) fac=gcd(sum,div);
        else div=1;
        ans[Q[i].id].l=sum/fac,ans[Q[i].id].r=div/fac;
    }
    for(int i=0;i<m;i++){
        cout<<ans[i].l<<"/"<<ans[i].r<<'\n';
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