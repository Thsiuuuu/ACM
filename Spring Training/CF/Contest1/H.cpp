#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

const int N=1e7;
bool vis[N+1];
vector<ll> prime;
ll f[N+2][3];
const ll mod=104206969;

void init(){
    for(ll i=2;i<=N;i++){
        if(!vis[i]){
            prime.push_back(i);
        }
        for(int j=0;j<prime.size();j++){
            if(i*prime[j]>N){
                break;
            }
            vis[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    ll tmp1=0,tmp2=0;
    for(int jl=0,jr=0,jm=0,i=1;i<=N;i++){
        if(jl<prime.size()&&prime[jl]<i-4){
            if(prime[jl]+2<=N&&prime[jl]+4<=N&&vis[prime[jl]+2]==false&&vis[prime[jl]+4]==false){
                // cout<<prime[jl]<<" ";
                tmp1++;
            }
            jl++;
        }
        if(jm<prime.size()&&prime[jm]<i-2){
            if(prime[jm]+2<=N&&vis[prime[jm]+2]==false) tmp2++;
            jm++;
        }
        if(jr<prime.size()&&prime[jr]<i) jr++;
        f[i][0]=(f[i-1][0]+jr)%mod;
        f[i][1]=(f[i-1][1]+(2*tmp2)%mod)%mod;
        f[i][2]=(f[i-1][2]+tmp1)%mod;
    }
}


void sol() {
    // cout<<'\n';
    // for(int i=0;i<8;i++) cout<<prime[i]<<" ";
    // cout<<'\n';
    // for(int i=1;i<=15;i++){
    //     cout<<g[i][0]<<" "<<g[i][1]<<" "<<g[i][2]<<'\n';
    // }
    int n,k;
    cin>>n>>k;
    if(k==1){
        cout<<n<<'\n';
    }else if(k>4){
        cout<<"0\n";
    }else{
        cout<<f[n][k-2]<<'\n';
    }
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