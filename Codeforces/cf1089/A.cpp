#include <bits/stdc++.h>
using namespace std;


#define ll long long 
#define pii pair<int,int>
#define pil pair<int,ll> 
#define pll pair<ll,ll>
#define i128 __int128_t
#define ld long double 

const ll mod=998244353; 

ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        b>>=1,a=a*a%mod;
    }
    return res;
}


void sol(){
    int n;
    cin>>n;
    for(int i=n;i>=1;i--){
        cout<<i<<" ";
    }
    cout<<'\n';
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}