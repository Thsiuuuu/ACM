#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
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
/*
多测清空，long long ，是否对需要修改的变量赋值了
想不出来注意换思路
注意数据范围，枚举答案是否可行
*/
const int N=2e6+10;
const ll mod=998244353;
int n,k;
ll f[N],last[26],pre[N];
void sol() {
    cin>>n>>k;
    string s(n+1,' ');
    for(int i=1;i<=n;i++) cin>>s[i];
    pre[0]=f[0]=1;
    for(int i=1;i<=k;i++) f[i]=0;
    for(int i=1;i<=n+k;i++) pre[i]=0;
    for(int i=0;i<26;i++) last[i]=0;
    for(int i=1;i<=n;i++){
        int x=s[i]-'a';
        if(last[x]==0) f[i+k]=pre[i-1];
        else f[i+k]=(pre[i-1]-pre[last[x]-1]+mod)%mod;
        pre[i]=(pre[i-1]+f[i])%mod;
        last[x]=i;
    }
    ll ans=0;
    for(int i=1;i<=n+k;i++){
        ans=(f[i]+ans)%mod;
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}