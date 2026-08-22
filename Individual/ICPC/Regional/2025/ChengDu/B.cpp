#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>


非常精妙啊！    
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

const ll INF=-1e18;

VLL mul(const VLL&a,const VLL&b){
    int n=a.size();
    VLL c(n,VL(n,INF));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(min(a[i][k],b[k][j])==INF) continue;
                else c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
            }
        }
    }
    return c;
}

VLL ksm(VLL&a,ll b){
    int n=a.size();
    VLL res(n,VL(n,0));
    while(b){
        if(b&1){
            res=mul(res,a);
        }
        b>>=1,a=mul(a,a);
    }
    return res;
}
void sol() {
    ll n,m,k,r;
    cin>>n>>m>>k>>r;
    VLL M(1<<n,VL(1<<n,INF));
    VL f(1<<n,0);
    VL a(n),c(n),A(1<<n,0),C(1<<n,0);
    for(int i=0;i<n;i++) cin>>a[i]>>c[i];
    for(ll s=0;s<(1<<n);s++){
        for(int i=0;i<n;i++){
            if((s>>i)&1) A[s]+=a[i],C[s]+=c[i];
        }
    }
    for(ll s=0;s<(1<<n);s++){
        for(ll t=0;t<(1<<n);t++){
            if(C[s]+__builtin_popcount(s&t)*k<=m) M[t][s]=A[s];
        }
    }
    VLL MF=ksm(M,r);
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<(1<<n);j++){
            f[i]=max(f[i],MF[j][i]);
        }
    }
    cout<<*max_element(f.begin(),f.end())<<'\n';
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