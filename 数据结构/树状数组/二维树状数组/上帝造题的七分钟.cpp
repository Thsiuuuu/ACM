#include <bits/stdc++.h>
using namespace std;

using namespace std;
#define int long long 

struct BIT{
    int n,m;
    vector<vector<int>> t1,t2,t3,t4;
    int lowbit(int x){
        return x&(-x);
    }

    void add(int x,int y,int val){
        for(int i=x;i<=n;i+=lowbit(i)){
            for(int j=y;j<=m;j+=lowbit(j)){
                t1[i][j]+=val;
                t2[i][j]+=val*x;
                t3[i][j]+=val*y;
                t4[i][j]+=val*x*y;
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
                res+=(x+1)*(y+1)*t1[i][j]-(y+1)*t2[i][j]-(x+1)*t3[i][j]+t4[i][j];
            }
        }
        return res;
    }

    int range_query(int xa,int ya,int xb,int yb){
        return query(xb,yb)-query(xb,ya-1)-query(xa-1,yb)+query(xa-1,ya-1);
    }

    BIT(int n,int m,const vector<vector<int>>&a):n(n),m(m){
        t1.resize(n+2,vector<int>(m+2,0));
        t2.resize(n+2,vector<int>(m+2,0));
        t3.resize(n+2,vector<int>(m+2,0));
        t4.resize(n+2,vector<int>(m+2,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                range_add(i,j,i,j,a[i][j]);
            }
        }
    }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    char x;
    int n,m;
    cin>>x>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=0;
        }
    }
    BIT tree(n,m,a);
    char op;
    while(cin>>op){
        if(op=='L'){
            int a,b,c,d,k;
            cin>>a>>b>>c>>d>>k;
            tree.range_add(a,b,c,d,k);
        }else{
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            cout<<tree.range_query(a,b,c,d)<<'\n';
        }
    }
    return 0;
}