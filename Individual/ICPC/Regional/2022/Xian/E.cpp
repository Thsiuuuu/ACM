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
// void init(){
//     int n;cin>>n;
//     VI f(n+1,0);
//     f[0]=1;
//     for(int i=1;i<=n;i++){
//         if(i%3 )f[i]=f[i-1]+1;
//         else f[i]=f[i/3]+1;
//         cout<<i-1<<" "<<f[i-1]<<'\n';
//     }
//     cout<<n<<" "<<f[n]<<'\n';
// }
#define Wo [pos][isL][isR][isZ]
const int N=48;
int f[N][2][2][2];
ll l,r;
deque<int> tl,tr;
int dfs(int pos,int isL,int isR,int isZ){
    if(pos==tl.size()) return 0;
    if(f Wo!=-1) return f Wo;
    int uL=isL?tl[pos]:0,
        uR=isR?tr[pos]:2;
    for(int x=uL;x<=uR;x++){
        int nL=isL&&(x==uL),
            nR=isR&&(x==uR),
            nZ=isZ&&(x==0);
        f Wo=max(f Wo,x+(nZ==0)+dfs(pos+1,nL,nR,nZ));
    }
    return f Wo;
}
void get(deque<int>&ff,ll x){
    while(x){
        ff.push_front(x%3);
        x/=3;
    }
}
void sol() {
    cin>>l>>r;
    tl.clear(),tr.clear();
    get(tl,l),get(tr,r);
    while(tl.size()<tr.size()) tl.push_front(0);
    for(int i=0;i<48;i++){
        for(int j=0;j<2;j++) for(int k=0;k<2;k++) for(int l=0;l<2;l++) f[i][j][k][l]=-1;
    }
    cout<<dfs(0,1,1,1)<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    // init();
    while (t--) {
        sol();
    }
    return 0;
}