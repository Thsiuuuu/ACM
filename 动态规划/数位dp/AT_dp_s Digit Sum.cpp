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
const ll mod=1e9+7;
const int N=10004;
ll f[N][101][2];
string s;
int d,siz;
ll dfs(ll pos,ll r,bool is){
    if(pos==siz-1) return r==0;
    if(f[pos][r][is]!=-1) return f[pos][r][is];
    f[pos][r][is]=0;
    int up=9;
    if(is) up=s[pos+1]-'0';
    for(int x=0;x<=up;x++){
        bool nxt=is&&(x==up);
        f[pos][r][is]+=dfs(pos+1,(r+x)%d,nxt);
        f[pos][r][is]%=mod;
    }
    return f[pos][r][is];
}
void sol() {
    cin>>s>>d;
    s=' '+s;
    siz=s.size();
    for(int i=0;i<siz;i++){
        for(int x=0;x<101;x++){
            for(int is=0;is<2;is++){
                f[i][x][is]=-1;
            }
        }
    }
    cout<<(dfs(0,0,1)-1+mod)%mod;
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