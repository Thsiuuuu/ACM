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
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;mp[x]++;
    }
    set<int> st;
    int q;cin>>q;
    while(q--){
        int k;cin>>k;
        auto[it,is]=st.insert(k);
        if(!is) st.erase(it);
    }
    vector<int> query(st.begin(),st.end());
    vector<int> need;
    for(int i=0;i<=n;i++){
        if(!mp[i]) need.push_back(i);
    }
    int ans=0;
    for(auto k:query){
        if(k>=2*n){
            for(int x:need){
                if(x==n||!mp[k-x]){
                    ans^=x;
                    break;
                }
            }
        }else{
            for(int x=0;x<=n;x++){
                int sum=mp[x]+mp[k-x];
                if(sum==0){ans^=x;break;}
                else if(sum==1&&2*x>k&&k-x>=0) {ans^=x;break;}
            }
        }
    }
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