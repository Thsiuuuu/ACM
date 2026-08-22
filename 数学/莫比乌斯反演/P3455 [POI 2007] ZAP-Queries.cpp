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
const int N=5e4+10;
int primes[N],cnt,mu[N],s[N];
bool vis[N];
void init( ){
    mu[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i])
            primes[cnt++]=i,mu[i]=-1;
        for(int j=0;j<cnt&&primes[j]*i<N;j++){
            vis[primes[j]*i]=true;
            if(i%primes[j]==0){
                break;
            }
            mu[primes[j]*i]=-mu[i];
        }
    }
    for(int i=1;i<N;i++){
        //计算莫比乌斯函数的前缀和
        s[i]=s[i-1]+mu[i];
    }
}
int g(int n,int i){
    //整除分块，求解跟n / i同样值的最大的右边界r
    return n/(n/i);
}
ll f(int n,int m){
    //算技巧2最右侧式子的函数。
    ll res=0;
    int rn=min(n,m);
    for(int l=1,r;l<=rn;l=r+1){
        r=min({rn,g(n,l),g(m,l)});
        res+=1ll*(s[r]-s[l-1])*(n/l)*(m/l);
    }
    //枚举每个d,让两个下取整都是常数，并且维护前缀和
    return res;
}
void sol() {
    int a,b,k;cin>>a>>b>>k;
    cout<<f(a/k,b/k)<<'\n';
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