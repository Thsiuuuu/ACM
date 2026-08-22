#include <bits/stdc++.h>
using namespace std;
/*

    比较妙的一道数学题
    这个曼哈顿距离可以转化为每一维的数的运算方法的排列组合
    等价于在每一维前面分配正负号，然后进行运算，总共k位，所以说共有(2^k)种分配方法
    然后可以交换max的次序，等价于对每一种运算情况下，该种运算值最大的点减去值最小的点，最后再取一次最大值
    所以说是一个单点修改，区间查询的问题，线段树维护即可
    
    但是线段树写的太史了....
    结构体内部的变量分配在栈上，如果申请空间过大会栈溢出


    constexpr在编译阶段就必须确定,const可以在运行阶段确定
*/
#define ll long long 


static constexpr int N=2e5+10;
ll mx[N<<2][32],mn[N<<2][32];
ll a[N][6];

struct SegTree{
    int n,k;

    SegTree(vector<vector<ll>> &a_,int n_,int k_):n(n_),k(k_){
        for(int i=1;i<a_.size();i++){
            for(int j=1;j<a_[i].size();j++){
                a[i][j]=a_[i][j];
            }
        }
    }

    void up(int i){
        for(int mask=0;mask<=(1<<k)-1;mask++){
            mx[i][mask]=max(mx[i<<1][mask],mx[i<<1|1][mask]);
            mn[i][mask]=min(mn[i<<1][mask],mn[i<<1|1][mask]);
        }
    }

    void build(int l,int r,int i){
        for(int mask=0;mask<=(1<<k)-1;mask++){
            mx[i][mask]=mn[i][mask]=0;
        }
        int mid=(l+r)>>1;
        if(l==r){
            for(int mask=0;mask<=(1<<k)-1;mask++){
                for(int j=1;j<=k;j++){
                    if(mask&(1<<(j-1))){
                        mx[i][mask]+=a[l][j];
                        mn[i][mask]+=a[l][j];
                    }else{
                        mx[i][mask]-=a[l][j];
                        mn[i][mask]-=a[l][j];
                    }
                }
            }
            return ;
        }
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }

    void change(int l,int r,int i,int jobi){
        if(l==r){
            for(int mask=0;mask<=(1<<k)-1;mask++){
                mx[i][mask]=0;
                mn[i][mask]=0;
                for(int j=1;j<=k;j++){
                    if(mask&(1<<(j-1))){
                        mx[i][mask]+=a[l][j];
                        mn[i][mask]+=a[l][j];
                    }else{
                        mx[i][mask]-=a[l][j];
                        mn[i][mask]-=a[l][j];
                    }
                }
            }
            return ;
        }
        int mid=(l+r)>>1;
        if(jobi<=mid){
            change(l,mid,i<<1,jobi);
        }else{
            change(mid+1,r,i<<1|1,jobi);
        }
        up(i);
    }

    void query(int l,int r,int jobl,int jobr,int i,vector<ll>& minans,vector<ll>& maxans){
        if(jobl<=l&&r<=jobr){
            // vector<vector<ll>> ans((1<<k),vector<ll>(2));//0,1分别表示最小值和最大值
            for(int mask=0;mask<=(1<<k)-1;mask++){
                minans[mask]=min(minans[mask],mn[i][mask]);
                maxans[mask]=max(maxans[mask],mx[i][mask]);
                // ans[mask][0]=INT64_MAX;
                // ans[mask][1]=INT64_MIN;
                // ans[mask][0]=min(mn[i][mask],ans[mask][0]);
                // ans[mask][1]=max(mx[i][mask],ans[mask][1]);
            }   
            // return ans;
        }else{
            int mid=(l+r)>>1;
            // vector<vector<ll>> ans((1<<k),vector<ll>(2));
            // for(int mask=0;mask<=(1<<k)-1;mask++){
            //     ans[mask][0]=INT64_MAX;
            //     ans[mask][1]=INT64_MIN;
            // }   
            if(mid>=jobl){
                query(l,mid,jobl,jobr,i<<1,minans,maxans);
                // for(int mask=0;mask<=(1<<k)-1;mask++){
                //     minans[mask]=min(ans[mask][0],cur[mask][0]);
                //     maxans[mask]=max(maxans[mask],cur[mask][1]);
                // }
            }
            if(mid+1<=jobr){
                query(mid+1,r,jobl,jobr,i<<1|1,minans,maxans);
                // for(int mask=0;mask<=(1<<k)-1;mask++){
                //     ans[mask][0]=min(ans[mask][0],cur[mask][0]);
                //     ans[mask][1]=max(ans[mask][1],cur[mask][1]);
                // }
            }
            // return ans;
        }
    }
};

void sol() {
    int n,k;
    cin>>n>>k;
    vector<vector<ll>> pt(n+1,vector<ll>(k+1,0ll));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin>>pt[i][j];
        }
    }
    SegTree tree(pt,n,k);
    tree.build(1,n,1);
    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int i;
            cin>>i;
            for(int j=1;j<=k;j++){
                cin>>pt[i][j];
                a[i][j]=pt[i][j];
            }
            tree.change(1,n,1,i);
        }else{
            int l,r;
            cin>>l>>r;
            vector<ll> minans((1<<k),INT64_MAX),maxans((1<<k),INT64_MIN);
            tree.query(1,n,l,r,1,minans,maxans);
            ll mx=-1;
            for(int mask=0;mask<=(1<<k)-1;mask++){
                mx=max(mx,maxans[mask]-minans[mask]);
            }
            cout<<mx<<'\n';
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