#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
const int N=2e5+10;
int d[N<<2],b[N<<2],a[N],cha[N],v[N<<2];
void build(int s,int t ,int p){
    v[p]=b[p]=0;
    if(s==t){
        d[p]=cha[s];
        return ;
    }
    int m=s+((t-s)>>1);
    build(s,m,p<<1),build(m+1,t,p<<1|1);
    d[p]=d[p<<1]+d[p<<1|1];
}
void update(int l,int r,int c,int s,int t,int p){
    if(l<=s&&t<=r){
        d[p]=(t-s+1)*c,b[p]=c,v[p]=1;
        return ;
    }
    int m=s+((t-s)>>1);
    if(v[p]){
        d[p<<1]=b[p]*(m-s+1),d[p<<1|1]=b[p]*(t-m);
        b[p<<1]=b[p<<1|1]=b[p];
        v[p<<1]=v[p<<1|1]=1;
        v[p]=0;
    }
    if(l<=m) update(l,r,c,s,m,p<<1);
    if(r>m) update(l,r,c,m+1,t,p<<1|1);
    d[p]=d[p<<1]+d[p<<1|1];
}
int getsum(int l,int r,int s,int t,int p){
    if(l<=s&&t<=r )return d[p];
    int m=s+((t-s)>>1);
    if(v[p]){
        d[p<<1]=b[p]*(m-s+1),d[p<<1|1]=b[p]*(t-m);
        b[p<<1]=b[p<<1|1]=b[p];
        v[p<<1]=v[p<<1|1]=1;
        v[p]=0;
    }
    int sum=0;
    if(l<=m) sum=getsum(l,r,s,m,p<<1);
    if(r>m) sum+=getsum(l,r,m+1,t,p<<1|1);
    return sum;
}
void sol() {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1) cha[i]=a[i];
        else cha[i]=(a[i]!=a[i-1]);
    }
    build(1,n,1);
    // cout<<getsum(1,n,1,n,1)<<'\n';
    while(m--){
        int op,l,r;cin>>op>>l>>r;
        if(op==1){
            int x;cin>>x;
            int S1=(l>1)?getsum(l-1,l-1,1,n,1):0; 
            // cout<<S1<<"#\n";  
            update(l,l,(x!=(S1&1)),1,n,1);
            // cout<<(x!=(S1&1))<<"#\n";
            if(l+1<=r){
                update(l+1,r,0,1,n,1);
            }
            // cout<<getsum(1,n,1,n,1)<<"#\n";
            if(r+1<=n){
                S1=getsum(r,r,1,n,1);
                int S2=getsum(r+1,r+1,1,n,1);
                update(r+1,r+1,(abs(S2-S1)!=x),1,n,1); 
            }   
            // cout<<getsum(1,n,1,n,1)<<"#\n";
        }else if(op==2){
            int S1=getsum(l,l,1,n,1);
            update(l,l,abs(S1-1),1,n,1);
            if(r+1<=n){
                S1=getsum(r+1,r+1,1,n,1);
                update(r+1,r+1,abs(S1-1),1,n,1);
            }
        }else{
            if(l+1<=r) cout<<getsum(l+1,r,1,n,1)<<"\n";
            else cout<<"0\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}