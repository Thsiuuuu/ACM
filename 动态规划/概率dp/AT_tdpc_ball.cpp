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
ld f[1<<19];
bool is[19];
int S,n;
bool ck(int mask,int i){
    return (mask>>i)&1;
}
void sol() {
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        S|=(1<<(x));
        is[x]=1;
    } 
    for(int mask=1;mask<(1<<16);mask++){
        f[mask]=1e18;
        for(int i=1;i<16;i++){
            int num=3-(ck(mask,i-1)+ck(mask,i)+ck(mask,i+1));
            if(num==3) continue;
            else{
                ld sum=0;
                if(ck(mask,i-1)) sum+=f[mask^(1<<(i-1))];
                if(ck(mask,i)) sum+=f[mask^(1<<i)];
                if(ck(mask,i+1)) sum+=f[mask^(1<<(i+1))]; 
                f[mask]=min(f[mask],(3+sum)/(3-num));
            }
        }
    }
    cout<<fixed<<setprecision(9)<<f[S]<<'\n';
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