#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

const int N=1e6+10;
namespace Trie{
    constexpr int MAXH=32;//数据位宽，根据数据范围动态调整
    
    struct Node{
        int son[2];//走法：左0右1
        int cnt;//一个节点子树有多少数的奇偶性（动态调整，也可以是数量）
        // ll val;//子树的异或和

        void init(){
            son[0]=son[1]=0;
            cnt=
            // val=
            0;    
        }
    }tr[N*MAXH];

    int tot;//节点总数
    void init(){
        tot=0;
        tr[0].init();
    }

    int MakeNode(){
        tr[++tot].init();
        return tot;
    }

    //insert或erase之后更新自己节点的状态
    void PushUp(int u){
        tr[u].cnt=0;
        // tr[u].val=0;

        if(tr[u].son[0]){
            int ls=tr[u].son[0];
            tr[u].cnt+=tr[ls].cnt;
            // tr[u].val^=tr[ls].val;
        }

        if(tr[u].son[1]){
            int rs=tr[u].son[1];
            tr[u].cnt+=tr[rs].cnt;
            // tr[u].val^=tr[rs].val;
        }
    }

    void insert(int root,int x){
        int u=root;
        for(int i=MAXH-1;i>=0;i--){
            tr[u].cnt++;
            // tr[u].val^=x;
            if(!tr[u].son[(x>>i)&1]) tr[u].son[(x>>i)&1]=MakeNode();
            u=tr[u].son[(x>>i)&1];
        }
        tr[u].cnt++;
        // tr[u].val^=x;
    }

    //u表示当前节点编号,x表示要插入或者删除的值,cur表示当前需要连第几位的边
    void erase(int u,int x,int cur){
        if(u==0&&cur!=MAXH-1) return ;
        if(cur<0){
            tr[u].cnt--;
            // tr[u].val^=x;
            return ;
        }
        erase(tr[u].son[(x>>cur)&1],x,cur-1);
        PushUp(u);
    }
}

void sol() {
    int n;ll k;
    cin>>n>>k;
    Trie::init();
    int def0=0;
    Trie::insert(def0,0);
    ll ans=0,pre=0;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        pre^=x;
        int idx=0;
        for(int cur=31;cur>=0;cur--){
            if(!((k>>cur)&1)){
                if(Trie::tr[idx].son[((pre>>cur)&1)^1]) ans+=Trie::tr[Trie::tr[idx].son[((pre>>cur)&1)^1]].cnt;
                if(Trie::tr[idx].son[(pre>>cur)&1]) idx=Trie::tr[idx].son[(pre>>cur)&1];
                else break;
            } 
            else{
                if(Trie::tr[idx].son[((pre>>cur)&1)^1]) idx=Trie::tr[idx].son[((pre>>cur)&1)^1];
                else break;
            }
            if(!cur) ans+=Trie::tr[idx].cnt;
        }
        Trie::insert(def0,pre);
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