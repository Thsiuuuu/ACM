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
const int N = 5e3+ 10;
const ll INF=(1ll<<62);

namespace Trie{
constexpr int MAXH = 50;
struct Node{
    int son[2];
    int cnt;
    ll val; 
    void init(){
        son[0] = son[1] = 0;
        cnt = 0;
        val = 0;
    }
} tr[N*MAXH];

int tot,root;

void init(){
    tot =root= 0;
    tr[0].init();
}

int MakeNode(){
    tr[++tot].init();
    return tot;
}
void insert(int &u,ll x, int dep = 0){
    if(!u)	u = MakeNode();

    //到头了回撤
    if(dep == MAXH){
        tr[u].cnt++;
        return;
    }

    int b = (x >> dep) & 1;
    insert(tr[u].son[b], x, dep + 1);
}
int size(int root){
    if(!root)
        return 0;

    return tr[root].cnt;
}
struct ST{
    VLL st;
    ST(const VL&a){
        int n=a.size();
        int M=__lg(n)+1;
        st.assign(M,VL(n+1,INF));
        for(int i=1;i<n;i++){
            st[0][i]=a[i];
        }
        for(int k=1;k<M;k++){
            for(int i=1;i+(1<<k)-1<n;i++){
                st[k][i]=min(st[k-1][i],st[k-1][i+(1<<(k-1))]);
            }
        }
    }
    ll query(int l,int r){
        int k=__lg(r-l+1);
        return min(st[k][l],st[k][r-(1<<k)+1]);
    }
};
VL dfs(int u,int dep=0){
    if(dep==MAXH){
        VL f(tr[u].cnt+1,0);
        f[0]=INF;
        return f;
    }
    auto[ls,rs]=tr[u].son;
    if(!ls) return dfs(rs,dep+1);
    if(!rs) return dfs(ls,dep+1);
    VL L=dfs(ls,dep+1),R=dfs(rs,dep+1);
    int sizl=(int)L.size()-1,sizr=R.size()-1;
    if(sizl>sizr){
        swap(sizl,sizr);
        swap(L,R);
    }
    ll w=1ll<<dep;
    VL g(sizr+1,INF);
    for(int j=1;j<=sizr;j++){
        g[j]=R[j]+1ll*j*w;
    }
    ST s(g);
    VL f(sizl+sizr+1,INF);
    for(int k=1;k<=sizl+sizr;k++){
        for(int i=1;i<=sizl;i++){
            int l=max(1,abs(k-i)),r=min(sizr,k+i);
            if(l>r) continue;
            ll Mn=s.query(l,r);
            ll cur=L[i]+w*(i-k)+Mn;
            f[k]=min(f[k],cur);
        }
    }
    return f;
}

}
void sol() {
    int n;cin>>n;
    Trie::init();
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        Trie::insert(Trie::root,x);
    }
    VL f=Trie::dfs(Trie::root);
    cout<<f[1]<<'\n';
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