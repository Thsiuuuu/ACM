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
const int N=2e5+10;
int a[N],c[N];
namespace Trie{
    constexpr int MAXH=20;
    struct Node{
        int son[2];//走法：左0右1
        void init(){  
        }
    }tr[N*MAXH];
    int tot,root;//节点总数,root=0以0为根
    void init(){
        tot=root=0;
        tr[0].init();
    }
    int MakeNode(){
        tr[++tot].init();
        return tot;
    }
    //u表示当前节点编号,x表示要插入或者删除的值,cur表示当前需要连第几位的边
    void insert(int x){
        int u=root;
        for(int i=MAXH-1;i>=0;i--){
            if(!tr[u].son[(x>>i)&1]) tr[u].son[(x>>i)&1]=MakeNode();
            u=tr[u].son[(x>>i)&1];
        }
    }
    int dfs(int tmp){
        int u=0;
        int res=0;
        for(int i=MAXH-1;i>=0;i--){
            if(tr[u].son[!((tmp>>i)&1)])  u=tr[u].son[!((tmp>>i)&1)],res+=(1<<i);
            else u=tr[u].son[(tmp>>i)&1];
        }
        return res;
    }
}
void sol() {
    int n;cin>>n;
    for(int i=1;i<n;i++) cin>>a[i];
    Trie::init();
    for(int i=2;i<=n;i++){
        c[i]=c[i-1]^a[i-1];
        Trie::insert(c[i]);
    }
    for(int i=0;i<n;i++){
        if(Trie::dfs(i)<=n-1){
            cout<<i<<" ";
            for(int j=2;j<=n;j++) cout<<(c[j]^i)<<" ";
            break;
        }
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