#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
const int mod=1e9+7;
struct node{
    // int i;
    int l=0,r=0;
};

void sol() {
    int n;
    cin>>n;
    vector<node> tr(n+1);
    vector<int> f(n+1,0),siz(n+1,0);
    tr[0].l=1;
    for(int i=1;i<=n;i++){
        // tr[i].i=i;
        cin>>tr[i].l>>tr[i].r;
    }
    auto dfs1=[&](auto &&self,int i){
        if(tr[i].l==0){
            siz[i]=0;
            return ;
        }
        self(self,tr[i].l);
        self(self,tr[i].r);
        siz[i]=(siz[tr[i].l]+siz[tr[i].r]+4)%mod;
    };
    dfs1(dfs1,1);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<siz[i]<<" "<<'\n';
    // }
    f[0]=0;
    auto dfs2=[&](auto &&self,int i,int fa){
        if(i==0) return ;
        f[i]=(siz[i]+f[fa]+1)%mod;
        self(self,tr[i].l,i);
        self(self,tr[i].r,i);
    };
    dfs2(dfs2,1,0);
    for(int i=1;i<=n;i++){
        cout<<f[i]<<" ";
    }
    cout<<'\n';
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