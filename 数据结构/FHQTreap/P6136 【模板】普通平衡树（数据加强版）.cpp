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
ull state = chrono::steady_clock::now().time_since_epoch().count();
ull rng() {
    ull x = (state += 0x9e3779b97f4a7c15ULL);
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}
template<typename T,int MaxSize>
struct FHQ{
    struct Node{
        int ls,rs,size;
        ull priority;
        T key;
    }tr[MaxSize+1];
    int root=0,Total=0;
    FHQ(){
        tr[0]={0,0,0,rng(),0};
    }
    // int stk[MaxSize];  //存储节点进行垃圾回收使用，防止不断新增节点
    int create(T key){
        // int root=Top?stk[Top--]:++Total;
        int root=++Total;
        tr[root]={0,0,1,rng(),key};
        return root;
    }
    void pushup(int root){
        if(root==0) return ;
        tr[root].size=tr[tr[root].ls].size+tr[tr[root].rs].size+1;
    }
    void splitVal(int root,T key,int& x,int & y){
        if(root==0){
            x=y=0;
            return ;
        }
        if(key>=tr[root].key){
            x=root;//设为x树的右儿子，继续去当前树的右子树中找<=key的部分
            splitVal(tr[root].rs,key,tr[root].rs,y);
        }else{
            y=root;//设为y树的左儿子，继续去当前树的左子树中找>key的部分
            splitVal(tr[root].ls,key,x,tr[root].ls);
        }
        pushup(root);
    }//按值分裂
    void splitRank(int root,int size,int &x,int &y){
        if(root==0){
            x=y=0;
            return ;
        }
        if(tr[tr[root].ls].size+1<=size){
            x=root;
            splitRank(tr[root].rs,size-tr[tr[root].ls].size-1,tr[root].rs,y);
        }else{
            y=root;
            splitRank(tr[root].ls,size,x,tr[root].ls);
        }
        pushup(root);
    }//按排名分裂
    int merge(int x,int y){
        if(x==0||y==0) return x+y;
        if(tr[x].priority>tr[y].priority){
            tr[x].rs=merge(tr[x].rs,y);
            pushup(x);
            return x;
        }else{
            tr[y].ls=merge(x,tr[y].ls);
            pushup(y);
            return y;
        }
    }
    void insert(T key){
        int x,y;
        splitVal(root,key-1,x,y);
        root=merge(merge(x,create(key)),y);
    }//分成<=key-1,>=key，新建节点并且合并
    void remove(T key){
        int x,y,z;
        splitVal(root,key,x,z);
        splitVal(x,key-1,x,y);
        if(y){//如果删除所有就删掉这个if，直接裸的merge <val,>val即可，并且下面只合并x,z
            // if(Top<(MaxSize>>8)-5) stk[++Top]=y;
            y=merge(tr[y].ls,tr[y].rs);//删除一个就是丢掉自己合并左右子树
        } 
        root=merge(merge(x,y),z);
    }//拆成[x,y,z]=[<key,key,>key]
    int rank(T key){
        int x,y,ans;
        splitVal(root,key-1,x,y);
        ans=tr[x].size+1;
        root=merge(x,y);
        return ans;
    }
    //每次按照size进行查找
    T KthVal(int k){
        int rt=root;
        while(true){
            if(tr[tr[rt].ls].size+1==k) break;
            else if(tr[tr[rt].ls].size+1>k) rt=tr[rt].ls;
            else k-=tr[tr[rt].ls].size+1,rt=tr[rt].rs;
        }
        return tr[rt].key;
    }
    // //把树分成三颗，去中间的，常数较大
    // int KthVal(int k){
    //     int x,y,z;
    //     splitRank(root,k-1,x,y);
    //     splitRank(y,1,y,z);
    //     T ans=tr[y].key;
    //     root=merge(merge(x,y),z);
    //     return ans;
    // }
    T prev(T key){//分裂成key-1的树，一直向右下走
        int x,y,rt;
        T ans;
        splitVal(root,key-1,x,y);
        rt=x;
        while(tr[rt].rs) rt=tr[rt].rs;
        ans=tr[rt].key;
        root=merge(x,y);
        return ans;
    }
    T next(T key){//分裂出>=key的树并不断向左下走
        int x,y,rt;
        T ans;
        splitVal(root,key,x,y);
        rt=y;
        while(tr[rt].ls) rt=tr[rt].ls;
        ans=tr[rt].key;
        root=merge(x,y);
        return ans;
    }
    int size(){
        return tr[root].size;
    }
    bool find(T key){//分裂出值均为key的树
        int x,y,z;
        splitVal(root,key,x,z);
        splitVal(x,key-1,x,y);
        bool ans;
        ans=tr[y].size;
        root=merge(merge(x,y),z);
        return ans;
    }
};
const int N=3e6+10;
FHQ<ll,N> fhq;
int last=0,ans=0,n,m;
void sol() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        fhq.insert(x);
    }
    for(int i=0;i<m;i++){
        int op,x;cin>>op>>x;
        x^=last;
        // cout<<op<<" "<<x<<'\n';
        if(op==1) fhq.insert(x);
        if(op==2) fhq.remove(x);
        if(op==3){
            int val=fhq.rank(x);
            ans^=val;
            last=val;
        }
        if(op==4){
            int val=fhq.KthVal(x);
            ans^=val;
            last=val;
        }
        if(op==5){
            int val=fhq.prev(x);
            ans^=val;
            last=val;
        }
        if(op==6){
            int val=fhq.next(x);
            ans^=val;
            last=val;
        }
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