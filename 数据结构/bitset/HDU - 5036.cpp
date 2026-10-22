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
bitset<1001> f[1001];
void sol() {
    ld ans=0;
    int n;cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) f[i][j]=0;
    for(int i=0;i<n;i++) f[i][i]=1;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int x;cin>>x;
            f[i][x-1]=1;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(f[i][k]){
                f[i]|=f[k];
            }
        }
    }
    for(int i=0;i<n;i++){
        ll sum=0;
        for(int j=0;j<n;j++){
            if(f[j][i]) sum++;
        }
        ans+=1.0/sum;
    }
    cout<<fixed<<setprecision(5)<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": "; 
        sol();
    }
    return 0;
}