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
const int N=5002;
int n,m;
int h[N];
ll f[N];
VI ban[N];
void sol() {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        ban[b].push_back(a);
    }
    ll ans=0;
    stack<int> stk;
    h[0]=-1,f[0]=0;
    stk.push(0);
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++) h[j]+=1,f[j]=0;
        for(int bb:ban[i]) h[bb]=0;
        while(stk.top()!=0) stk.pop();
        for(int j=1;j<=n;j++){
            while(h[stk.top()]>=h[j]) stk.pop();
            f[j]=f[stk.top()]+(j-stk.top())*1ll*h[j];
            ans+=f[j];
            stk.push(j);
        }
    }
    cout<<ans;
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