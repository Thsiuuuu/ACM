#include <bits/stdc++.h>
using namespace std;
/*

    归并，就是线段树不断归并的思想，用线段树模拟就可以

*/

const int N=3e5;
int sum[N<<2],a[N],siz[N<<2];

void up(int i){
    sum[i]=sum[i<<1]^sum[i<<1|1];
    siz[i]=siz[i<<1]+siz[i<<1|1];
}

void build(int l,int r,int i){
    if(l==r){
        siz[i]=1,sum[i]=a[l];
    }else{
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
}

void change(int l,int r,int ji,int val,int i,int &p){
    if(l==r){
        sum[i]=val;
    }else{
        int mid=(l+r)>>1;
        if(ji<=mid){
            change(l,mid,ji,val,i<<1,p);
            if(sum[i<<1]<sum[i<<1|1]){
                p+=siz[i<<1|1];
            }
        }else{
            change(mid+1,r,ji,val,i<<1|1,p);
            if(sum[i<<1]>=sum[i<<1|1]){
                p+=siz[i<<1];
            }
        }
        up(i);
    }
}

void sol() {
    int n,q;
    cin>>n>>q;
    n=(1<<n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,n,1);
    while(q--){
        int ans=0;
        int b,c;
        cin>>b>>c;
        change(1,n,b,c,1,ans);
        cout<<ans<<'\n';
        change(1,n,b,a[b],1,ans);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}