#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
vector<int> a;

struct SegTree{
    int n;
    vector<int> mn,tag,sum;
    SegTree(int n_):n(n_),mn((n+2)<<2,0),tag((n+2)<<2,0),sum((n+2)<<2,0){}
    void build(int i,int l,int r){
        if(l==r){
            mn[i]=sum[i]=a[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(i<<1,l,mid),build(i<<1|1,mid+1,r);
        sum[i]=sum[i<<1]+sum[i<<1|1];
        mn[i]=min(mn[i<<1],mn[i<<1|1]);
    }
    void down(int i,int l,int r){
        if(tag[i]){
            tag[i<<1]=tag[i<<1|1]=tag[i];
            int mid=(l+r)>>1;
            sum[i<<1]=(mid-l+1)*tag[i],sum[i<<1|1]=(r-mid)*tag[i];
            mn[i<<1]=tag[i],mn[i<<1|1]=tag[i];
            tag[i]=0;
        }
    }

    void change(int i,int l,int r,int jobl,int jobr,int val){
        if(jobl<=l&&r<=jobr){
            tag[i]=val;
            sum[i]=(r-l+1)*val;
            mn[i]=val;
            return ;
        }
        int mid=(l+r)>>1;
        down(i,l,r);
        if(jobl<=mid) change(i<<1,l,mid,jobl,jobr,val);
        if(jobr>mid) change(i<<1|1,mid+1,r,jobl,jobr,val);
        sum[i]=sum[i<<1]+sum[i<<1|1];
        mn[i]=min(mn[i<<1],mn[i<<1|1]);
    }

    int querypos(int i,int l,int r,int val){
        if(l==r){
            if(val>sum[i]) return l;
            return l+1;
        }
        int mid=(l+r)>>1;
        down(i,l,r);
        if(mn[i<<1]>=val) return querypos(i<<1|1,mid+1,r,val);
        return querypos(i<<1,l,mid,val);
    }

    int query(int i,int l,int r,int jobl,int &y){
        if(r<jobl||y<mn[i]) return 0;
        if(l>=jobl&&y>=sum[i]){
            y-=sum[i];
            return min(n,r)-l+1;
        }
        down(i,l,r);
        int mid=(l+r)>>1,ans=0;
        if(mid>=jobl) ans+=query(i<<1,l,mid,jobl,y);
        ans+=query(i<<1|1,mid+1,r,jobl,y);
        return ans;
    }
};

void sol() {
    int n,q;
    cin>>n>>q;
    a.resize(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    SegTree tree(n);
    tree.build(1,1,n);
    while(q--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            int l=tree.querypos(1,1,n,y);
            if(l<=x) tree.change(1,1,n,l,x,y);
        }else cout<<tree.query(1,1,n,x,y)<<'\n';
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