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
map<int,int> wadasiyouwocaonimahajimionameiluduoaxikayahayaku[3];
void sol() {
    int n,m;cin>>n>>m;
    map<tuple<int,int,int>,int> mp;
    for(int i=0;i<3;i++) wadasiyouwocaonimahajimionameiluduoaxikayahayaku[i].clear();
    for(int i=0;i<n;i++){
        int x,y,z;cin>>x>>y>>z;
        mp[{x,y,z}]++;
        wadasiyouwocaonimahajimionameiluduoaxikayahayaku[0][x]++;
        wadasiyouwocaonimahajimionameiluduoaxikayahayaku[1][y]++;
        wadasiyouwocaonimahajimionameiluduoaxikayahayaku[2][z]++;
    }
    for(int i=0;i<m;i++){
        int x,y,z;cin>>x>>y>>z;
        if(mp[{x,y,z}]==1) mp[{x,y,z}]=0,wadasiyouwocaonimahajimionameiluduoaxikayahayaku[0][x]--,wadasiyouwocaonimahajimionameiluduoaxikayahayaku[1][y]--,wadasiyouwocaonimahajimionameiluduoaxikayahayaku[2][z]--;
        else mp[{x,y,z}]=1,wadasiyouwocaonimahajimionameiluduoaxikayahayaku[0][x]++,wadasiyouwocaonimahajimionameiluduoaxikayahayaku[1][y]++,wadasiyouwocaonimahajimionameiluduoaxikayahayaku[2][z]++;
    }
    int cnt=0;
    for(auto [key,val]:mp){
        cnt+=val;
    }
    bool is=true;
    for(int i=0;i<3;i++){
        for(auto [key,val]:wadasiyouwocaonimahajimionameiluduoaxikayahayaku[i]) if((val&1)){is=false;break;}
    }
    cout<<((!is||(cnt&1))?"NO\n":"YES\n");
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