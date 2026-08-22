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
int f[21][1<<21][2];
int c[21];
void sol() {
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        c[i]--;
    }
    if(m==1){
        cout<<"1\n";
        return ;
    }
    f[1][0][0]=f[1][0][1]=0,f[1][1][0]=f[1][1][1]=1;
    for(int i=2;i<=n;i++){
        for(int mask=0;mask<(1<<i);mask++){
            int tmp0=0,tmp1=1;
            for(int j=1;j<=k;j++){
                if(c[j]>=i) break;
                int aft=(((mask>>(c[j]+1))<<c[j])
                        |
                         (mask&((1<<c[j])-1))
                        );
                tmp0|=f[i-1][aft][1],tmp1&=f[i-1][aft][0];
            }
            f[i][mask][0]=tmp0,f[i][mask][1]=tmp1;
        }
    }
    ll ans=0;
    for(int mask=0;mask<(1<<n);mask++) ans+=(f[n][mask][0]+1);
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