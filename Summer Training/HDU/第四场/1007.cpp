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
struct DSU{
    VII zi;
    VI siz,fa;
    int n;
    DSU(int n):n(n),siz(n+1,1),fa(n+1,0),zi(n+1,VI(26,0)){
        for(int i=0;i<n;i++) fa[i]=i;
    }
    int find(int x){
        return x==fa[x]?x:fa[x]=find(fa[x]);
    }
    void unite(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx^fy){
            if(siz[fx]<siz[fy]) swap(fx,fy);
            siz[fx]+=siz[fy];
            fa[fy]=fx;
            for(int i=0;i<26;i++){
                zi[fx][i]+=zi[fy][i];
            }
        }
    }
};
void sol() {
    int n,d;cin>>n>>d;
    string s;cin>>s;
    DSU dsu(n);
    for(int i=0;i<n;i++){
        dsu.zi[i][s[i]-'a']++;
    }
    vector<bool> v1(n,false),v2(n,false);
    for(int i=0;i<=n-i+1;i++){
        int j=n-i+1;
        for(int k=0;!v1[(i+(ll)k*d)%n]||!v1[(j+(ll)k*d)%n];k++){
            dsu.unite((i+(ll)k*d)%n,(j+(ll)k*d)%n);
            v1[(i+(ll)k*d)%n]=v1[(j+(ll)k*d)%n]=true;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        int fi=dsu.find(i);
        if(!v2[fi]){
            ll sum=0;
            v2[fi]=true;
            for(int k=0;k<26;k++){
                sum=max(sum,(ll)dsu.zi[fi][k]);
            }
            ans+=((ll)dsu.siz[fi]-sum);
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