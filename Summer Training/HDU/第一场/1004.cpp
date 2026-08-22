#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
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
struct node{
    ll a,b;
    int idx;
    bool operator<(const node&o)const{
        return (i128)b*o.a>(i128)o.b*a;
    }  
};
const int N=2e5+10;
int fa[N],p[N];
ll na[N],nb[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unite(int x,int  y,ll&ans){
    int fx=find(x),fy=find(y);
    ans+=nb[fx]*na[fy];
    na[fx]+=na[fy];
    nb[fx]+=nb[fy];
    fa[fy]=fa[fx];
}
void sol() {
    int n;cin>>n;
    vector<node> all(n);
    for(int i=1;i<=n;i++){
        na[i]=nb[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>all[i].a;
        na[i+1]=all[i].a;
        all[i].idx=i+1;
    }
    priority_queue<node,vector<node>> Q;
    for(int i=0;i<n;i++){
        cin>>all[i].b;
        nb[i+1]=all[i].b;
        Q.push(all[i]);
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;

        cin>>p[i];
    } 
    ll ans=0;
    while(Q.size()){
        while(Q.size()&&(na[find(Q.top().idx)]!=Q.top().a||nb[find(Q.top().idx)]!=Q.top().b)) Q.pop();
        if(Q.empty()) break;
        auto [a,b,idx]=Q.top();
        Q.pop();
        if(idx!=1){
            unite(find(p[idx]),idx,ans);
            Q.push({na[find(idx)],nb[find(idx)],find(idx)});
        }
    }
    cout<<ans<<'\n';
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