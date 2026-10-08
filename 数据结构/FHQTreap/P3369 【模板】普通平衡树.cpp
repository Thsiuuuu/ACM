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
mt19937 sj(114514);
const int N=1e5+20;
template<typename T,int MaxSize>
struct FHQ{
    struct Node{
        int ls,rs,size;
        ull priority;
        T key;
    }tr[N];
    int root,Total;
    // int stk[MaxSize];  //存储节点进行垃圾回收使用，防止不断新增节点
    int create(T key){
        // int root=Top?stk[Top--]:++Total;
        int root=++Total;
        tr[root]={0,0,1,(ull)sj(),key};
        return root;
    }
    void pushup(int root){
        if(root==0) return ;
        tr[root].size=tr[tr[root].ls].size+tr[tr[root].rs].size+1;
    }
    void split(int root,T key,int& x,int & y){
        if(root==0){
            x=y=0;
            return ;
        }
        if(key>=tr[root].key){
            x=root;
            split(tr[root].rs,key,tr[root].rs,y);
        }else{
            y=root;
            split(tr[root].ls,key,x,tr[root].ls);
        }
        pushup(root);
    }//按值分裂
    void split(int root,int size,int &x,int &y){
        if(root===0){
            x=y=0;
            return ;
        }
        if(tr[tr[root].ls].size+1<=size){
            x=root;
            split(tr[root].rs,size-tr[tr[root].ls].size-1,tr[root].rs,y);
        }else{
            y=root;
            split(tr[root].ls,size,x,tr[root].rs);
        }
        pushup(root);
    }
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
        split(root,key-1,x,y);
        root=merge(merge(x,create(key)),y);
    }
    void remove(T key){
        int x,y,z;
        split(root,key,x,z);
        split(x,key-1,x,y);
        if(y){//如果删除所有就删掉这个if，直接裸的merge <val,>val即可，并且下面只合并x,z
            // if(Top<(MaxSize>>8)-5) stk[++Top]=y;
            y=merge(tr[y].ls,tr[y].rs);//删除一个就是丢掉自己合并左右子树
        } 
        root=merge(merge(x,y),z);
    }//拆成[x,y,z]=[<key,key,>key]

};
void sol() {
    
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