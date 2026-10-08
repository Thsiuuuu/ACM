#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
// #define int long long 
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
const int N=2e6+10;
bool vis[N+1];
ll prime[N/2+1];
int cnt=0;
void init(){
    for(ll i=2;i<N;i++){
        if(!vis[i]){
            prime[cnt++]=i;
        }
        for(int j=0;j<cnt;j++){
            if(i*prime[j]>=N){
                break;
            }
            vis[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}
void sol() {
    map<set<int>,int> mp;
    int n;cin>>n;
    VI a(n+1);
    set<int> cr;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int x=a[i];
        for(ll j=0;j<cnt&&prime[j]*prime[j]<=x;j++){
            if(x%prime[j]==0){
                int cnt=0;
                while(x%prime[j]==0){
                    x/=prime[j];
                    cnt++;
                }
                if(cnt&1){
                    if(cr.find(prime[j])!=cr.end()) cr.erase(prime[j]);
                    else cr.insert(prime[j]);
                }
            }
        }
        if(x>1){
            if(cr.find(x)!=cr.end()) cr.erase(x);
            else cr.insert(x);
        }
        if(cr.size()>=8) continue;
        mp[cr]++;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        cr.clear();
        int x=a[i];
        for(ll j=0;j<cnt&&prime[j]*prime[j]<=x;j++){
            if(x%prime[j]==0){
                int cnt=0;
                while(x%prime[j]==0){
                    x/=prime[j];
                    cnt++;
                }
                if(cnt&1){
                    if(cr.find(prime[j])!=cr.end()) cr.erase(prime[j]);
                    else cr.insert(prime[j]);
                }
            }
        }
        if(x>1){
            if(cr.find(x)!=cr.end()) cr.erase(x);
            else cr.insert(x);
        }
        ans+=mp[cr];
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    init();
    while (t--) {
        sol();
    }
    return 0;
}