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

const int N=6e5+10;
int n,m,is[N],nxt[N],ans1,ans2;
struct P{
    int x,y;
    int id;
}a[N],b[N];
void dfs(int u){
    is[u]=2;
    int v=nxt[u];
    if(!v){
        is[u]=1;
        return ;
    }
    if(is[v]==-1){
        dfs(v);
    }
    if(is[v]!=2) is[u]=!is[v];
}
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x;
    for(int i=1;i<=n;i++) cin>>a[i].y;
    cin>>m;
    for(int i=1;i<=m;i++) cin>>b[i].x;
    for(int i=1;i<=m;i++) cin>>b[i].y;
    for(int i=1;i<=n;i++) a[i].id=i;
    for(int i=1;i<=m;i++) b[i].id=i+n;
    for(int i=1;i<=n+m;i++){
        nxt[i]=0,is[i]=-1;
    }
    ans1=ans2=0;
    sort(a+1,a+1+n,[&](P &x,P &y)->bool{
        return x.y>y.y;
    });
    sort(b+1,b+m+1,[&](P &x,P&y)->bool{
        return x.x>y.x;
    });
    int mx=0;
    for(int i=1,j=1;i<=n;i++){
        while(j<=m&&b[j].x> a[i].y){
            if(b[j].y>b[mx].y){
                mx=j;
            }
            j++;
        }
        if(mx) nxt[a[i].id]=b[mx].id;
    }
    mx=0;
    sort(b+1,b+1+m,[&](P &x,P &y)->bool{
        return x.y>y.y;
    });
    sort(a+1,a+n+1,[&](P &x,P&y)->bool{
        return x.x> y.x;
    });
    for(int i=1,j=1;i<=m;i++){
        while(j<=n&&a[j].x>b[i].y){
            if(a[j].y>a[mx].y){
                mx=j;
            }
            j++;
        }
        if(mx) nxt[b[i].id]=a[mx].id;
    }
    for(int i=1;i<=n+m;i++){
        if(is[i]==-1) dfs(i);
    }
    for(int i=1;i<=n;i++){
        if(is[i]==0) ans2++;
        else if(is[i]==1) ans1++;
    }
    cout<<ans1<<" "<<n-ans1-ans2<<" "<<ans2<<'\n';
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