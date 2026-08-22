#include <bits/stdc++.h>
using namespace std;
/*

    首先注意到从大到小一定是可以的，因为>=k一定就>=k-1
    
    应该进行n-1轮合并
    每轮合并需要差值分别为n-1 n-2 ... 2 1
    
    对于一个线段来说，可能有多个点，如果多次计算必然会超时
    如果一个线段是k-的话，那么任意一个字段都是，等价于从n个点中任取两个点连接成线段有多少种方法，总共的方案数就是Cn,2
    所以每一轮不断进行合并，并减去合并之前的贡献，加上现在的贡献

    这里编码上利用了一些小巧思
    对每组相邻项的权值都存到了一起，然后把对应相邻项的进行合并


*/

#define int long long 

struct DSU{
    int n;
    vector<int> fa,siz;
    DSU(int n_):n(n_),fa(n_),siz(n_){
        for(int i=0;i<n;i++){
            fa[i]=i;
            siz[i]=1;
        }
    }
    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }
    void unite(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx^fy){
            if(siz[fx]<siz[fy]){
                swap(fx,fy);
            }
            siz[fx]+=siz[fy];
            fa[fy]=fx;
        }
    }

    int cal(int x){
        int fx=find(x);
        return siz[fx]*(siz[fx]-1)/2;
    }

};



void sol() {
    int n;
    cin>>n;
    vector<int> a(n),ans(n,0);
    DSU dsu(n);
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i){
            mp[llabs(a[i]-a[i-1])].push_back(i);
        }
    } 
    int cur=0;
    for(int i=n-1;i>=1;i--){
        for(int y:mp[i]){
            cur-=dsu.cal(y-1);
            cur-=dsu.cal(y);
            dsu.unite(y,y-1);
            cur+=dsu.cal(y);
        }
        ans[i]=cur;
    } 
    for(int i=1;i<=n-1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
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