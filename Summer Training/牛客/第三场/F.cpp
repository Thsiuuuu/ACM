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
const ll mod=998244353;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
void sol() {
    int n;ll m;cin>>n>>m;
    if(n==1){
        cout<<3*ksm(2,m-1)%mod;
        return ;
    }
    VLL st;
    VL cr(n);
    cr[0]=0,cr[1]=1;
    auto dfs=[&](auto&&self,int step)->void{
        if(step==n){
            st.push_back(cr);
            return ;
        }
        for(int x=0;x<3;x++){
            if(x==cr[step-1]) continue;
            cr[step]=x;
            self(self,step+1);
        }
    };
    dfs(dfs,2);
    vector<array<int,3>> all;
    array<int,3> p={0,1,2};
    do{
        all.push_back(p);
    }while(next_permutation(p.begin(),p.end()));
    int siz=st.size();
    VLL T(siz,VL(siz));
    for(int i=0;i<siz;i++){
        for(int j=0;j<siz;j++){
            for(auto pp:all){
                bool ok=true;
                for(int r=0;r<n;r++){
                    if(pp[st[j][r]]==st[i][r]){
                        ok=false;
                        break;
                    }
                }
                T[i][j]+=ok;
            }
        }
    }
    VL f(siz,6);
    m--;
    while(m){
        if(m&1){
            VL tmp(siz);
            for(int j=0;j<siz;j++){
                for(int i=0;i<siz;i++){
                    tmp[j]+=f[i]*T[i][j]%mod;
                    tmp[j]%=mod;
                }
            }
            f=tmp;
        }
        VLL tmp(siz,VL(siz));
        for(int i=0;i<siz;i++){
            for(int j=0;j<siz;j++){
                for(int k=0;k<siz;k++){
                    tmp[i][j]+=T[i][k]*T[k][j]%mod;
                    tmp[i][j]%=mod;
                }
            }
        }
        T=tmp;
        m>>=1;
    }
    ll ans=0;
    for(int i=0;i<siz;i++){
        ans+=f[i];
        ans%=mod;
    }
    cout<<ans;
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