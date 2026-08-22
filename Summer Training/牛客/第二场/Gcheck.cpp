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
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

const int n=1e6+10;
bool vis[n+1];
int prime[n/2+1];
int cnt=0;
void sol() {
    // for(int n=2;n<=1000010;n++){
    //     bool f=false;
    //     for(int i=1;i<n;i++){
    //         if(gcd(i,n)==1){
    //             f=true;
    //             break;
    //         }else{
    //             for(int j=i+1;j<n;j++){
    //                 if(gcd(i,j)==1&&gcd(j,n)==1){
    //                     f=true;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     if(!f){
    //         cout<<n<<'\n';
    //         cout<<"NO\n";
    //     }
    // }
    // cout<<"YES\n";
    //每个数都一定由自己最小的质因数被除掉
    //但是要判断一下如果一个数能够被当前的因子整除的话
    //那么到了他们之间的质因子时，就不是一个数被最小的质因数整除了，因为大的数可以被拆解为它的因子
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            prime[cnt++]=i;
            cout<<prime[cnt]<<'\n';
        }
        for(int j=0;j<cnt;j++){
            if(i*prime[j]>n){
                break;
            }
            cout<<i<<" "<<j<<'\n';
            vis[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    // ll sum=0;
    // for(int i=1;i<=99;i++){
    //     if(i%2==0||i%5==0) sum++;
    // }
    // cout<<sum;
    // int l,r;cin>>l>>r;
    // int n;cin>>n;
    // ll ans=0;
    // for(int i=l;i<=r;i++){
    //     if(gcd(i,n)==1){
    //         ans++;
    //     }
    // }
    // ans=2*(r-l+1)-ans;
    // cout<<ans<<'\n';
    // cout<<gcd(3,6)<<'\n';
    // int sum=0;
    // for(int i=l;i<=r;i++){
    //     for(int j=i+1;j<=n;j++){
    //         if(gcd(i,j)==1&&gcd(j,n)==1){
    //             cout<<i<<" "<<j<<'\n';
    //             sum++;
    //             break;
    //         }
    //     }
    // }
    // cout<<sum<<'\n';
    // for(int x=1;x+1<=n-1;x++){
    //     if(gcd(x,n-1)!=1&&gcd(x,n)!=1){
    //         cout<<n<<" "<<x<<'\n';
    //     }
    // }
    // for(int i=3;i<=n;i++){
    // }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}