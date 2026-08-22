#include <bits/stdc++.h>
using namespace std;
/*

    手玩发现如果一种糖>k个，那么一定会发生重复，如果<=k个，不会发生重复
    又因为一定保证每个人都有糖，所以说就是每种糖尽可能的散开，散不开再增加怒气值
    那么答案就等于所有超过k的数量的糖-k的数量的和

    但是这个不好维护，因为需要遍历种类
    如果维护种类比较困难，就去维护数量
    维护每个数量有多少种糖
    需要快速对某一个数量有多少种糖进行修改，以及查询它的前缀和
    可以用树状数组，进行单点修改，区间查询，维护两部分的和i*si和si，si表示i数量的糖有多少种

    需要对0边界进行特判处理

*/
#define int long long
const int N=2e6+4;

struct BIT{
    int n;
    vector<int> cnt;

    BIT():n(N),cnt(N,0){

    }

    int lowbit(int x){
        return x&(-x);
    }

    void add(int x,int val){
        while(x<=n){
            cnt[x]+=val;
            x+=lowbit(x);
        }
    }

    int query(int x){
        int ans=0;
        while(x){
            ans+=cnt[x];
            x-=lowbit(x);
        }
        return ans;
    }

    int ask(int l,int r){
        return query(r)-query(l-1); 
    }
};


void sol() {
    int n,q;
    cin>>n>>q;
    vector<int> num(n+1,0);

    
    BIT tree1,tree2;


    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(num[x]>0){
            tree1.add(num[x],-num[x]);
            tree2.add(num[x],-1);
        }
        tree1.add(num[x]+1,num[x]+1);
        tree2.add(num[x]+1,1);
        num[x]++;
    }
    while(q--){
        int op,x;
        cin>>op>>x;
        if(op==1){
            if(num[x]>0){
                tree1.add(num[x],-num[x]);
                tree2.add(num[x],-1);
            }
            tree1.add(num[x]+1,num[x]+1);
            tree2.add(num[x]+1,1);
            num[x]++;
        }else if(op==2){
            if(num[x]-1>0){
                tree1.add(num[x]-1,num[x]-1);
                tree2.add(num[x]-1,1);
            }
            tree1.add(num[x],-num[x]);
            tree2.add(num[x],-1);
            num[x]--;
        }else{
            cout<<((tree1.ask(x+1,N-4))-x*(tree2.ask(x+1,N-4)))<<'\n';
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