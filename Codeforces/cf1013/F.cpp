#include <bits/stdc++.h>
using namespace std;
/*

    第一次切1800
    dp方程很好想，分成从本层转移和上一层转移
    上一层转移就是在半径d内进行范围转移
    本层转移也是在半径d内进行范围转移
    所以说可以用前缀和记录区间的dp和，先更新上一轮的
    然后开一个temp数组记录这一层的dp区间和，并继续维护本轮相互转移之后的区间和

*/
#define ll long long
#define double long double
const ll mod=998244353; 

void sol() {
    int n,m,d;
    cin>>n>>m>>d;
    vector<string> s(n+1);
    for(int i=n;i>=1;i--){
        cin>>s[i];
        s[i]=' '+s[i];
    }
    vector<vector<ll>> f(n+1,vector<ll>(m+1,0ll));
    vector<ll> temp(m+1,0ll);
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='X'){
                if(i>1){
                    int l=max((int)ceil(j-sqrtl((double)d*d-1)),1),r=min((int)floorl(j+sqrtl((double)d*d-1)),m);
                    // cout<<l<<" "<<r<<'\n';
                    f[i][j]=(f[i][j]+f[i-1][r]-f[i-1][l-1]+mod)%mod;
                }else{
                    f[i][j]=1;
                }
            }
            temp[j]=(f[i][j]+temp[j-1])%mod;
        }
        // cout<<"temp: ";
        // for(int j=1;j<=m;j++){
        //     cout<<temp[j]<<" ";
        // }
        // cout<<'\n';
        for(int j=1;j<=m;j++){
            if(s[i][j]=='X'){
                int l=max(j-d,1),r=min(j+d,m);
                f[i][j]=(temp[r]-temp[l-1]+mod)%mod;
            }
            f[i][j]=(f[i][j]+f[i][j-1])%mod;
            if(i==n){
                ans=(ans+f[i][j]-f[i][j-1]+mod)%mod;
            }
        }
        // cout<<"f   : ";
        // for(int j=1;j<=m;j++){
        //     cout<<f[i][j]<<" ";
        // }
        // cout<<'\n';
    }
    cout<<ans<<'\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}