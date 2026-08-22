#include <bits/stdc++.h>
using namespace std;

#define int long long 

struct BIT{
    int n,m;

    vector<vector<int>> c;


    int lowbit(int x){
        return x&(-x);
    }
    void add(int x,int y,int val){
        for(int i=x;i<=n;i+=lowbit(i)){
            for(int j=y;j<=m;j+=lowbit(j)){
                c[i][j]+=val;
            }
        }
    }

    int sum(int x,int y){
        int res=0;
        for(int i=x;i>0;i-=lowbit(i)){
            for(int j=y;j>0;j-=lowbit(j)){
                res+=c[i][j];
            }
        }
        return res;
    }

    int query(int x1,int y1,int x2,int y2){
        return sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1);
    }

    BIT(int n,int m):n(n),m(m){
        c.resize(n+1,vector<int>(m+1,0));

    }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    
    // vector<vector<int>> a(n+1,vector<int>(m+1));
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         a[i][j]=0;
    //     }
    // }
    
    BIT tree(n,m);
    int op;
    while(cin>>op){
        if(op==1){
            int x,y,k;
            cin>>x>>y>>k;
            tree.add(x,y,k);
        }else{
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            cout<<(tree.query(a,b,c,d))<<'\n';
        }
    }
    return 0;
}