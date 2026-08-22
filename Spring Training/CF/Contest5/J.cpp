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


const int N=1e6+10;
vector<int> prime,Mn(N+1,-1);
vector<bool> vis(N+1,false);
void init(){
    for(int i=2;i<=N;i++){
        if(!vis[i]){
            prime.push_back(i);
        }
        for(int j=0;j<prime.size();j++){
            if(i*prime[j]>N){
                break;
            }
            vis[i*prime[j]]=vis[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    vis[1]=false;
    for(int i=0;i<prime.size();i++){
        for(int j=prime[i];j<=N;j+=prime[i]){
            if(!vis[j]||Mn[j]!=-1) continue;
            Mn[j]=prime[i];
        }
    }
}



void sol() {
    int n;
    cin>>n;
    int sum1=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(!vis[x]) ans++;
        else{
            if(vis[x/Mn[x]]) sum1++;
            else ans++;
        }
    }
    ans+=(sum1+1)/2;
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