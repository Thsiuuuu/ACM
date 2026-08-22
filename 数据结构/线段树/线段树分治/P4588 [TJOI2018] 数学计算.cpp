#include <bits/stdc++.h>   
using namespace std;
#define ll long long 

const int N=1e5+10;
ll mul[N<<2];

ll q,mod;

void up(int i){
    mul[i]=mul[i<<1]*mul[i<<1|1]%mod;
}

void build(int i,int l,int r){
    if(l==r){
        mul[i]=1;
    }else{
        int mid=(l+r)>>1;
        build(i<<1,l,mid);
        build(i<<1|1,mid+1,r);
        up(i);
    }
}

void change(int ji,int jv,int i,int l,int r){
    if(l==r){
        mul[i]=jv;
    }else{
        int mid=(l+r)>>1;
        if(ji<=mid){
            change(ji,jv,i<<1,l,mid);
        }else{
            change(ji,jv,i<<1|1,mid+1,r);
        }
        up(i);
    }
}

void sol(){
    cin>>q>>mod;
    build(1,1,q);
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==1){
            int m;cin>>m;
            change(i,m,1,1,q);
        }else{
            int pos;cin>>pos;
            change(pos,1,1,1,q);
        }
        cout<<mul[1]<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}