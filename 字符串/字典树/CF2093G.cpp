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

const int N=2e5+10;
namespace Trie{
    constexpr int MAXH=32;//数据位宽，根据数据范围动态调整
    
    struct Node{
        int son[2];//走法：左0右1
        // int cnt;//一个节点子树有多少个数
        // int val;//子树的异或和

        int mx;
        void init(){
            son[0]=son[1]=0;
            // cnt=0;    
            mx=-1;
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

    // //insert或erase之后更新自己节点的状态
    // void PushUp(int u){
    //     tr[u].cnt=0;
    //     tr[u].val=0;

    //     if(tr[u].son[0]){
    //         int ls=tr[u].son[0];
    //         tr[u].cnt+=tr[ls].cnt;
    //         // tr[u].val^=tr[ls].val;
    //     }

    //     if(tr[u].son[1]){
    //         int rs=tr[u].son[1];
    //         tr[u].cnt+=tr[rs].cnt;
    //         // tr[u].val^=tr[rs].val;
    //     }
    // }

    //u表示当前节点编号,x表示要插入或者删除的值,cur表示当前需要连第几位的边
    void insert(int x,int idx){
        int u=root;
        for(int i=MAXH-1;i>=0;i--){
            // tr[u].cnt++;
            // tr[u].val^=x;
            if(!tr[u].son[(x>>i)&1]) tr[u].son[(x>>i)&1]=MakeNode();
            u=tr[u].son[(x>>i)&1];
            tr[u].mx=idx;
        }
        // tr[u].cnt++;
        // tr[u].val^=x;
    }

    // bool erase(int u,int x,int cur){
    //     if(u==0&&cur!=MAXH-1) return false;
    //     if(cur<0){
    //         tr[u].cnt--;
    //         // tr[u].val^=x;
    //         return true;
    //     }
    //     if(erase(tr[u].son[(x>>cur)&1],x,cur-1)){
    //         PushUp(u);
    //         if(tr[tr[u].son[(x>>cur)&1]].cnt==0){
    //             tr[u].son[(x>>cur)&1]=0;
    //         }
    //         return true;
    //     }
    // }
}

void sol() {
    Trie::init();
    int n,k;
    cin>>n>>k;
    int ans=INT32_MAX;
    for(int i=0;i<n;i++){
        // cout<<'\n'<<i<<'\n';
        int x;cin>>x;
        Trie::insert(x,i+1);
        int idx=0;
        for(int cur=Trie::MAXH-1;cur>=0;cur--){
            // cout<<ans<<" ";
            int kb=(k>>cur)&1,xb=(x>>cur)&1;
            if(kb){
                if(Trie::tr[idx].son[xb^1]){
                    idx=Trie::tr[idx].son[xb^1];
                    if(!cur) ans=min(ans,i+2-Trie::tr[idx].mx);
                }
                else break;
            }else{
                if(Trie::tr[idx].son[xb^1]) ans=min(ans,i+2-Trie::tr[Trie::tr[idx].son[xb^1]].mx);
                if(Trie::tr[idx].son[xb]){
                    idx=Trie::tr[idx].son[xb];
                    if(!cur) ans=min(ans,i+2-Trie::tr[idx].mx);
                }
                else break;
            }
        }
    }
    if(ans==INT32_MAX) ans=-1;
    cout<<ans<<'\n';
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