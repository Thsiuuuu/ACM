#include <bits/stdc++.h>
using namespace std;
/*

    https://codeforces.com/problemset/problem/1679/C

    如果行和列放一块比较复杂，就分开来看
    对于一行或一列而言，只有第一次出现和最后一次删除会影响这一行或列的答案
    所以需要在这两种情况分别记录一下

    如果说一行没有凑满的话，就需要列是满的
    反之也是
    所以，如果能够每一行或列都被覆盖的话，就是可以的
    简单的单点修改，区间查询，树状数组维护即可
*/

struct BIT{
    int n;
    vector<int> c;
    int lowbit(int x){
        return x&(-x);
    }

    void add(int i,int v){
        while(i<=n){
            c[i]+=v;
            i+=lowbit(i);
        }
    }

    int getsum(int i){
        int res=0;
        while(i){
            res+=c[i];
            i-=lowbit(i);
        }
        return res;
    }

    int query(int l,int r){
        return getsum(r)-getsum(l-1);
    }

    BIT(int n):n(n),c(n+1,0){}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,q;
    cin>>n>>q;
    vector<int> x(n+1,0),y(n+1,0);
    BIT xtree(n),ytree(n);
    while(q--){
        int a,b,c,d;
        int t;
        cin>>t;
        cin>>a>>b;
        if(t==1){
            x[a]++,y[b]++;
            if(x[a]==1){
                xtree.add(a,1);
            }
            if(y[b]==1){
                ytree.add(b,1);
            }
        }else if(t==2){
            x[a]--,y[b]--;
            if(x[a]==0){
                xtree.add(a,-1);
            }
            if(y[b]==0){
                ytree.add(b,-1);
            }
        }else{
            cin>>c>>d;
            if(xtree.query(a,c)==c-a+1||ytree.query(b,d)==d-b+1){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
    }
    return 0;
}