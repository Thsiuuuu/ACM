#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int T=4e6+10,N=1e5+3;
vector<int> e[N];
int cnt=0,sum[T],ls[T],rs[T],root[N],ans[N];

void up(int i){
    sum[i]=sum[ls[i]]+sum[rs[i]];
}

int build(int ji,int l,int r,int i){
    int idx=i;
    if(!idx) idx=++cnt;
    if(l==r){
        sum[idx]++;
    }else{
        int mid=(l+r)>>1;
        if(ji<=mid) ls[idx]=build(ji,l,mid,ls[idx]);
        else rs[idx]=build(ji,mid+1,r,rs[idx]);
        up(idx);
    }
    return idx;
}

int merge(int l,int r,int t1,int t2){
    if(t1==0||t2==0) return t1+t2;
    if(l==r) sum[t1]+=sum[t2];
    else{
        int mid=(l+r)>>1;
        ls[t1]=merge(l,mid,ls[t1],ls[t2]);
        rs[t1]=merge(mid+1,r,rs[t1],rs[t2]);
        up(t1);
    }
    return t1;
}

int query(int jl,int jr,int l,int r,int i){
    if(i==0) return 0;
    if(jl<=l&&r<=jr) return sum[i];
    int mid=(l+r)>>1;
    int res=0;
    if(jl<=mid) res+=query(jl,jr,l,mid,ls[i]);
    if(jr>mid) res+=query(jl,jr,mid+1,r,rs[i]);
    return res;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<int> p(n+1,0),b(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>p[i];
        b[i]=p[i];
    } 
    sort(b.begin()+1,b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=1;i<=n;i++){
        auto it=lower_bound(b.begin(),b.end(),p[i]);
        p[i]=it-b.begin();
    }

    for(int i=2;i<=n;i++){
        int x;cin>>x;
        e[x].push_back(i);
    }
    
    auto dfs=[&](auto &&self,int u)-> void{
        root[u]=build(p[u],1,b[b.size()-1],root[u]);
        for(int v:e[u]){
            self(self,v);
            merge(1,b[b.size()-1],root[u],root[v]);
        }
        ans[u]=query(p[u]+1,b[b.size()-1],1,b[b.size()-1],root[u]);
    };

    dfs(dfs,1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<'\n';
    }

    return 0;
}