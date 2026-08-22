#include <bits/stdc++.h>
using namespace std;

using namespace std;
#define int long long 

struct BIT{
    int n,m;
    vector<vector<int>> t;
    int lowbit(int x){
        return x&(-x);
    }

    void add(int x,int y,int val){
        for(int i=x;i<=n;i+=lowbit(i)){
            for(int j=y;j<=m;j+=lowbit(j)){
                t[i][j]+=val;
            }
        }
    }

    void range_add(int xa,int ya,int xb,int yb,int val){
        add(xa,ya,val);
        add(xa,yb+1,-val);
        add(xb+1,ya,-val);
        add(xb+1,yb+1,val);
    }

    int query(int x,int y){
        int res=0;
        for(int i=x;i>0;i-=lowbit(i)){
            for(int j=y;j>0;j-=lowbit(j)){
                res+=t[i][j];
            }
        }
        return res;
    }

    int range_query(int xa,int ya,int xb,int yb){
        return query(xb,yb)-query(xb,ya-1)-query(xa-1,yb)+query(xa-1,ya-1);
    }

    BIT(int n,int m):n(n),m(m){
        t.resize(n+2,vector<int>(m+2,0));

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         range_add(i,j,i,j,a[i][j]);
        //     }
        // }
    }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    // vector<vector<int>> a(n+1,vector<int>(m+1,0));
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         a[i][j]=0;
    //     }
    // }
    BIT tree(n,m);
    int op;
    while(cin>>op){
        if(op==1){
            int a,b,c,d,k;
            cin>>a>>b>>c>>d>>k;
            tree.range_add(a,b,c,d,k);
        }else{
            int x,y;
            cin>>x>>y;
            cout<<tree.query(x,y)<<'\n';
        }
    }
    return 0;
}