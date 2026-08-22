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

struct node{
    // int a,b;
    int idx;
    bool f;
    ll val;
    /*
        f=1,ji,f=0,ou
        idx suoyin
        val quanzhi
    */
   node(){};
   node(int idx,bool f,ll val):idx(idx),f(f),val(val){}
   bool operator<(const node&other)const{
        return val<other.val;
   }
};

struct DSU{
    vector<int> fa,siz;
    DSU(int n):fa(n+1),siz(n+1,1){
        for(int i=1;i<=n;i++) fa[i]=i;
    }
    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }
    bool unite(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx^fy){
            if(siz[fx]<siz[fy]) swap(fx,fy);
            siz[fx]+=siz[fy],fa[fy]=fx;
            return true;
        }
        else return false;
    }
};

void sol() {
    int n;
    cin>>n;
    ll ans=0;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<node> all;
    for(int i=0;i<n;i++){
        all.push_back(node(i,false,2*a[i]));
        if(i+1<n){
            all.push_back(node(i,true,(a[i]+a[i+1])));
        }
    }
    DSU dsu(n);
    sort(all.begin(),all.end());
    int siz=n-1;
    for(int i=0;i<all.size()&&siz;i++){
        auto [lf,f,val]=all[i];
        if(f){
            for(int rf=lf+1;rf<n&&lf>=0;lf--,rf++){
                if(dsu.unite(lf+1,rf+1)){
                    ans+=val;
                    siz--;
                }
            }
        }else{
            lf=lf-1;
            for(int rf=lf+2;rf<n&&lf>=0;lf--,rf++){
                if(dsu.unite(lf+1,rf+1)){
                    ans+=val;
                    siz--;
                }
            }
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