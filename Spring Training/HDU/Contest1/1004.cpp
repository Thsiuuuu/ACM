#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  

const int M=1e6+3;
ull hsh[M];
bool vis[M];
mt19937_64 rg(random_device{}());

void init(){
    for(int i=2;i<M;i++){
        if(!vis[i]){
            vis[i]=true,hsh[i]=rg();
            for(int j=i+i;j<M;j+=i){
                vis[j]=true,hsh[j]=hsh[j/i]^hsh[i];
            }
        }
    }
}

void sol() {
    int n;ll x,ans=0;cin>>n>>x;
    ull cur=0,T=hsh[x];
    map<ull,ll> mp;
    mp[0]=1;
    for(int i=1;i<=n;i++){
        int val;cin>>val;
        cur^=hsh[val];
        if(mp.find((cur^T))!=mp.end()) ans+=mp[cur^T];
        mp[cur]++;
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init();
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}