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

const int N=5e6;
bool vis[N+1];
vector<ll> prime;

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
}

void sol() {
    int n;
    cin>>n;
    cout<<"1 ";
    ll x=2;
    i128 tmp=2;
    for(int i=2,j=0;i<=n;i++){
        if(tmp*x*(prime[j+1])>1e18){
            cout<<(ll)tmp*(prime[j+1])<<" ";
            x=prime[++j];
            tmp=x*x;
        }else{
            cout<<(ll)tmp<<" ";
            tmp=tmp*x;
        }
    }
    cout<<'\n';
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