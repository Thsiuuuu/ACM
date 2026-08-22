#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
const ll mod=1e9+7;
const int N=2e3+10;
int n,m;
ll C[N][N];
int a[N];

void sol() {

    C[0][0]=1;
    for(int i=1;i<N;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<"i :"<<i<<"j :"<<j<<C[i][j]<<'\n';
    //     }
    // }
    ll ans=0;
    for(int i=0;i<=n;i++){
        ll mul=C[n][i];
        for(int j=1;j<=m;j++){
            mul=mul*C[n-i+a[j]-1][a[j]]%mod;  
        }
        if(i&1){
            mul=mod-mul;
        }
        ans=(ans+mul)%mod;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}