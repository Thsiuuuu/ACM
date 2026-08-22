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
ll x,y,z,n;
const int N=1500000;
const ll mod=1e9+7;
ll f[42][N];
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        b>>=1,a=a*a%mod;
    }
    return res;
}
bool check(ll mask,ll bit){
    return (mask>>(bit-1))&1;
}
void sol() {
    cin>>n>>x>>y>>z;
    f[0][0]=1;
    ll Lim=(1ll<<(x+y+z))-1;
    for(int i=1;i<=n;i++){
        for(ll Number=1;Number<=10;Number++){
            for(ll mask=0;mask<=Lim;mask++){
                ll CurMask=((mask<<Number)|(1ll<<(Number-1)))&Lim;
                if(check(CurMask,z)&&check(CurMask,y+z)&&check(CurMask,x+y+z)) continue;
                else{
                    f[i][CurMask]=(f[i][CurMask]+f[i-1][mask])%mod;
                }   
            }
        }
    }
    ll sum=0;
    for(ll mask=0;mask<=Lim;mask++){
        sum=(sum+f[n][mask])%mod;
    }
    cout<<(ksm(10,n)-sum+mod)%mod<<'\n';
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