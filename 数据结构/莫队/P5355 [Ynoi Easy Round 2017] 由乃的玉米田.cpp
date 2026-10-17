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
/*
多测清空，long long ，是否对需要修改的变量赋值了
想不出来注意换思路
注意数据范围，枚举答案是否可行
*/
const int N=1e5+3,K=316;
struct node{
    int l,r,id;
    int x;
    int op;
}Q[N];
int blo[N];
bool cmp(const node&a,const node&b){
    return blo[a.l]!=blo[b.l]?a.l<b.l:((blo[a.l]&1)?a.r<b.r:a.r>b.r);
}
int n,m,B;
bitset<N> f,g;
int last[N],tot,a[N],cnt[N];
bool ans[N];
void add(int i){
    int x=a[i];
    if(++cnt[x]==1){
        f[x]=1;
        g[N-x]=1;
    }
}
void sub(int i){
    int x=a[i];
    if(--cnt[x]==0){
        f[x]=0;
        g[N-x]=0;
    }
}
void sol() {
    cin>>n>>m;
    B=sqrt(n);
    for(int i=1;i<=n;i++) blo[i]=(i-1)/B;
    vector<vector<node>> small(K+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<m;i++){
        int op,l,r,x;cin>>op>>l>>r>>x;
        if(op<=3){
            Q[tot++]={l,r,i,x,op};
        }else{
            if(x==0) ans[i]=false;
            else if(x==1) ans[i]=true;
            else if(x>K) Q[tot++]={l,r,i,x,op};
            else small[x].push_back({l,r,i,x,op});
        }
    }
    sort(Q,Q+tot,cmp);
    for(int x=1;x<=K;x++){
        if(small[x].empty()) continue;
        sort(small[x].begin(),small[x].end(),[&](const node&a,const node&b){
            return a.r<b.r;
        });
        int idx=1;
        int best=0;
        for(int i=1;i<=n;i++) last[a[i]]=0;
        for(const auto&[l,r,id,val,op]:small[x]){
            while(idx<=r){
                if(1ll*a[idx]*val<N) best=max(best,last[a[idx]*val]); 
                if(a[idx]%val==0) best=max(best,last[a[idx]/val]);
                last[a[idx]]=idx;
                idx++;
            }
            if(best>=l) ans[id]=true;
        }
    }
    for(int i=0,l=1,r=0;i<tot;i++){
        while(l>Q[i].l) add(--l);
        while(r>Q[i].r) sub(r--);
        while(r<Q[i].r) add(++r);
        while(l<Q[i].l) sub(l++);
        int x=Q[i].x;
        if(Q[i].op==2){
            if((f&(g>>(N-x))).any()) ans[Q[i].id]=1;
        }else if(Q[i].op==1){
            if((f&(f>>x)).any()) ans[Q[i].id]=1;
        }else if(Q[i].op==3){
            for(int y=1;y<=K;y++){
                if(x%y||!f[y]||!f[x/y]) continue;
                ans[Q[i].id]=1;
                break;
            }
        }else{
            for(int y=1;y<=K&&1ll*x*y<N;y++){
                if(f[y]&&f[y*x]){
                    ans[Q[i].id]=1;
                    break;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<((ans[i]==1)?"yuno\n":"yumi\n");
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