#include <bits/stdc++.h>
using namespace std;
/*

    题中公式有单调性，进行移项会发现是个单调递减的函数，最多只有一个符合题意的d值
    考虑二分出d值
    因为找的是大于等于的，所以说要判断是不是等于，只有等于的时候才有1个值
    否则就是从大于直接跳到了小于，为0
*/


const int N=2e5+10;
int mn[N<<2],a[N];

void up(int i){
    mn[i]=min(mn[i<<1],mn[i<<1|1]);
}

void build(int l,int r,int i){
    if(l==r){
        mn[i]=a[l];
    }else{
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
}

void change(int l,int r,int i,int x,int p){
    if(l==r){
        mn[i]=x;
    }else{
        int mid=(l+r)>>1;
        if(p<=mid){
            change(l,mid,i<<1,x,p);
        }else{
            change(mid+1,r,i<<1|1,x,p);
        }
        up(i);
    }
}

int query(int l,int r,int jl,int jr,int i){
    if(jl<=l&&r<=jr){
        return mn[i];
    }else{
        int mid=(l+r)>>1;
        int ans=INT32_MAX;
        if(jl<=mid){ 
            ans=min(ans,query(l,mid,jl,jr,i<<1));
        }
        if(jr>mid){
            ans=min(ans,query(mid+1,r,jl,jr,i<<1|1));
        }
        return ans;
    }
}


void sol() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,n,1);
    while(q--){
        int idx;
        cin>>idx;
        if(idx==1){
            int i,x;
            cin>>i>>x;
            change(1,n,1,x,i);
        }else{
            int l,r;
            cin>>l>>r;
            int left=0,right=r-l;
            int mid;
            int ans=0;
            while(left<=right){
                mid=(left+right)>>1;
                if(query(1,n,l,l+mid,1)>=mid){
                    ans=mid;
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
            cout<<(query(1,n,l,l+ans,1)==(ans))<<'\n';
        }
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