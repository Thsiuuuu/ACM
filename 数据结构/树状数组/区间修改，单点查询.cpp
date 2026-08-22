#include <bits/stdc++.h>
using namespace std;

#define int  long long

struct BIT{
    int n;
    vector<int> diff,diffi;
    int lowbit(int x){
        return  x&(-x);
    }
    
    void add(int x,int k){
        int val=x*k;
        while(x<=n){
            diff[x]+=k;
            diffi[x]+=val;
            x+=lowbit(x);   
        }
    }
    
    void addRegion(int l,int r,int v){
        add(l,v);
        add(r+1,-v);
    }
    
    int getsum(vector<int> &t,int k){
        int res=0;
        while(k){
            res+=t[k];
            k-=lowbit(k);
        }
        return res;
    }
    
    int getsumRegions(int l,int r){
        return (r+1ll)*getsum(diff,r)-l*getsum(diff,l-1)-(getsum(diffi,r)-getsum(diffi,l-1));
    }
    BIT(int n,const vector<int>&a):n(n),diff(n+1),diffi(n+1){
        for(int i=1;i<=n;i++){
            int val=a[i]-a[i-1];
            // addRegion(i,i,val);
            add(i,val);
        }
    }//数组存的是区间和，不是单点和
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    BIT tree(n,a);
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int x,y,k;
            cin>>x>>y>>k;
            tree.addRegion(x,y,k);
        }else{
            int x;
            cin>>x;
            cout<<tree.getsumRegions(x,x)<<'\n';
        }
    }
    return 0;
}