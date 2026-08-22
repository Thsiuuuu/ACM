#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
const int M=18000000,N=5e5+10;
ll tr1[M],tr2[M],ans1=-1e18,ans2=-1e18;
int ls1[M],ls2[M],rs1[M],rs2[M],root1[N],root2[N],idx1,idx2,n;
struct node{
    ll a,b;
    int i;
    bool operator<(const node&other)const{
        return b-a<other.b-other.a;
    }
}clo[N];

void up1(int i){
    tr1[i]=max(tr1[ls1[i]],tr1[rs1[i]]);
}

void up2(int i){
    tr2[i]=max(tr2[ls2[i]],tr2[rs2[i]]);
}

int build(int l,int r,int &idx2){
    int i=++idx2;
    if(l==r){
        tr2[i]=clo[l].a;
    }else{
        int mid=(l+r)>>1;
        ls2[i]=build(l,mid,idx2);
        rs2[i]=build(mid+1,r,idx2);
        up2(i);
    }
    return i;
}

int del(int ji,int l,int r,int pre,int &idx2){
    int i=++idx2;
    if(l==r){
        tr2[i]=-1e18;
    }else{
        ls2[i]=ls2[pre],rs2[i]=rs2[pre];
        int mid=(l+r)>>1;
        if(ji<=mid){
            ls2[i]=del(ji,l,mid,ls2[pre],idx2);
        }else{
            rs2[i]=del(ji,mid+1,r,rs2[pre],idx2);
        }
        up2(i);
    }
    return i;
}

int add(int ji,int l,int r,int pre,int &idx1,int b){
    int i=++idx1;
    if(l==r){
        tr1[i]=b;
    }else{
        ls1[i]=ls1[pre],rs1[i]=rs1[pre];
        int mid=(l+r)>>1;
        if(ji<=mid){
            ls1[i]=add(ji,l,mid,ls1[pre],idx1,b);
        }else{
            rs1[i]=add(ji,mid+1,r,rs1[pre],idx1,b);
        }
        up1(i);
    }
    return i;
}

void query1(int jl,int jr,int l,int r,int i){
    if(!i) return ;
    if(jl<=l&&r<=jr) ans1=max(ans1,tr1[i]);
    else{
        int mid=(l+r)>>1;
        if(jl<=mid) query1(jl,jr,l,mid,ls1[i]);
        if(jr>=mid+1) query1(jl,jr,mid+1,r,rs1[i]);
    }
}

void query2(int  jl,int jr,int l,int r,int i){
    if(!i) return ;
    if(jl<=l&&r<=jr) ans2=max(ans2,tr2[i]);
    else{
        int mid=(l+r)>>1;
        if(jl<=mid) query2(jl,jr,l,mid,ls2[i]);
        if(jr>=mid+1) query2(jl,jr,mid+1,r,rs2[i]);
    }
}

void sol() {
    int n,q;cin>>n>>q;
    tr1[0]=tr2[0]=-1e18;
    for(int i=1;i<=n;i++){
        cin>>clo[i].a>>clo[i].b;clo[i].i=i;
    }
    root2[0]=build(1,n,idx2);
    sort(clo+1,clo+1+n);
    for(int i=1;i<=n;i++){
        root1[i]=add(clo[i].i,1,n,root1[i-1],idx1,clo[i].b);
        root2[i]=del(clo[i].i,1,n,root2[i-1],idx2);
    }
    ll last=0;
    while(q--){
        int l,r; ll x,y;cin>>l>>r>>x>>y;
        x=last^x,y=last^y;
        ans1=ans2=-1e18;
        int left=1,right=n,mid,cur=0;
        while(left<=right){
            mid=(left+right)>>1;
            if(clo[mid].b-clo[mid].a<=x-y){
                cur=mid;
                left=mid+1;
            }else right=mid-1;
        }
        query1(l,r,1,n,root1[cur]),query2(l,r,1,n,root2[cur]);
        if(ans1!=-1e18) ans1=ans1+y;
        if(ans2!=-1e18) ans2=ans2+x;
        last=max(ans1,ans2);
        cout<<last<<'\n';
        ans1=ans2=-1e18;
    }
    idx1=idx2=0;
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