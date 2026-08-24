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
const int N=4e5+10;
int n,m,k,B,blo[N],pr[N],cnt[N];
ll ans[N],sum;
struct node{
    int l,r,id;
    bool operator<(const node&o)const{
        return blo[l]!=blo[o.l]?l<o.l:((blo[l]&1)?r<o.r:r>o.r);
    }
}Q[N];
void add(int x){
    sum+=cnt[pr[x]^k];
    cnt[pr[x]]++;
}
void del(int x){
    cnt[pr[x]]--;
    sum-=cnt[pr[x]^k];
}
void sol() {
    cin>>n>>m>>k;
    B=n/sqrt(m);
    for(int i=1;i<=n;i++){
        cin>>pr[i];
        pr[i]^=pr[i-1];
        blo[i]=(i-1)/B;
    }
    for(int i=0;i<m;i++){
        cin>>Q[i].l>>Q[i].r;
        Q[i].id=i;
    }
    cnt[0]=1;
    sort(Q,Q+m);
    for(int i=0,l=1,r=0;i<m;i++){
        while(l>Q[i].l){--l,add(l-1);}
        while(r>Q[i].r) del(r--);
        while(r<Q[i].r) add(++r);
        while(l<Q[i].l){del(l-1);l++;}
        ans[Q[i].id]=sum;
    }
    for(int i=0;i<m;i++) cout<<ans[i]<<'\n';
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