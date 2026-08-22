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
VL in;
ll l,r,n;
ll ans=0,mul=1,qr;
const int N=1e7+10;
bool vis[N+1];
ll prime[N/2+1],pr[N+1];
int cnt=0;
void init(){
    for(int i=2;i<N;i++){
        if(!vis[i]){
            prime[cnt++]=i;
        }
        for(ll j=0;j<cnt;j++){
            if(i*prime[j]>=N){
                break;
            }
            vis[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
        pr[i]=pr[i-1];
        if(!vis[i]) pr[i]=i;
    }
}
ll cal(ll x){
    return qr/x-(l-1)/x;
}
void dfs(int cur,int level,int idx){
    if(cur==level){
        // cout<<level<<" ";
        // cout<<mul<<'\n';
        // cout<<cal(mul)<<'\n';
        ans+=((level&1)?1:-1)*cal(mul);
        return ;
    }
    for(int i=idx;i<in.size();i++){
        mul*=in[i];
        dfs(cur+1,level,i+1);
        mul/=in[i];
        // if(!vis[i]){
        //     // vis[i]=true;
        //     // vis[i]=false;
        // }
    }
}
void sol() {
    cin>>l>>r>>n;
    in.clear();
    ans=0,mul=1;
    int nt=n;
    for(ll i=2;i*i<=n;i++){
        if(nt%i==0){
            in.push_back(i);
            while(nt%i==0) nt/=i;
        }
    }
    if(nt>1) in.push_back(nt);
    // cout<<in.size()<<'\n';
    qr=min(pr[n-1],r);
    if(l<=qr){
        for(int level=1;level<=in.size();level++){
            dfs(0,level,0);
        }
        // cout<<ans<<'\n';
        ans=(qr-l+1)-ans;
        // cout<<ans<<'\n';
        ans=2ll*(qr-l+1)-ans;
    }
    if(qr<r){
        VL f(n-qr,0);
        for(int i=(int)f.size()-2;i>=0;i--){
            f[i]=1e18;
            for(int j=i+1;j<f.size();j++){
                f[i]=min(f[i],f[j]+gcd(i+pr[n-1]+1,j+pr[n-1]+1));
            }
            if(i+pr[n-1]+1<=r&&i+pr[n-1]+1>=l) ans+=f[i];
        }
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