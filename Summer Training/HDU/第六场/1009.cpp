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
void sol() {
    int n;cin>>n;
    vector<pair<pii,int>> mp1,mp2;
    
    for(int i=0;i<(1<<n);i++){
        int x;cin>>x;
        mp1.push_back(make_pair((pii){i,x},1));
    }
    for(int laiwo=n;laiwo>=1;laiwo--){
        vector<unordered_map<int,array<int,4>>> tmp(1<<(laiwo-1));
        for(const auto&[key,val]:mp1){
            auto[i,x]=key;
            // mp2[{i>>1,x>>1}]+=val;
            int p=(((i&1)<<1)|(x&1));
            tmp[i>>1][(x>>1)][p]=val;
        }
        for(int i=0;i<(1<<(laiwo-1));i++){
            for(const auto&[key,val]:tmp[i]){
                mp2.push_back(make_pair((pii){i,key},max(val[0]+val[3],val[1]+val[2])));
            }
        }
        swap(mp1,mp2);
        mp2.clear();
    }
    for(const auto&[key,val]:mp1){
        if(key==(pii){0,0}) cout<<val<<'\n';
    }
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