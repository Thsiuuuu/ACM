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
const int N=50001,B=sqrt(N);
bitset <N> f[5][B+3],tmp,cur;
int k,n,a[N][5],pos[5][N];
void sol() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) for(int j=0;j<k;j++){
        cin>>a[i][j];
        pos[j][a[i][j]]=i;
    }
    for(int j=0;j<k;j++){
        for(int c=B;c<=n;c+=B){
            int t=c/B;
            f[j][t]=f[j][t-1];
            for(int i=c-B+1;i<=c;i++){
                f[j][t][pos[j][i]]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        tmp.set();
        for(int j=0;j<k;j++){
            cur=f[j][a[i][j]/B];
            for(int l=a[i][j]/B*B+1;l<=a[i][j];l++){
                cur[pos[j][l]]=1;
            }
            tmp&=cur;
        }
        cout<<(int)tmp.count()-1<<'\n';
    }
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