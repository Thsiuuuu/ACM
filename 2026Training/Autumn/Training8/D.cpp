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
const int N=1e4+10;
int a[N],n,pos[N],vis[N];
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    if(n==1) return void(cout<<"0\n");
    ll ans=0;
    for(int L=1;L<=n;L++){
        for(int i=1;i<=n+1;i++) vis[i]=0;
        int cnt=0;
        for(int R=L;R<=n;R++){
            int p=pos[R];
            cnt+=1-vis[p-1]-vis[p+1];
            vis[p]=1;
            if(cnt<=2) ans++;
        }
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