#include <bits/stdc++.h>
using namespace std;
/*

    首先观察到最优方法一定是能/2就/2，否则-1

    /2转化为>>1
    一个数的操作次数就是popcount(x)+len(x)-1,len表示有多少位

    即求len-1>=popcount()-1>k-len+1的数量有多少个
    枚举len和popcount()-1即可

    因为每次都是枚举的每一位都是满的情况，所以说最后一个单独的n要单独判断
*/
#define int long long 
const int N=55;
int  c[N][N];

void init(){
    for(int i=0;i<=50;i++){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
}



void sol() {
    int n,k;
    cin>>n>>k;

    int lim=log2(n)+1;
    int ans=0;
    for(int len=1;len<=lim-1;len++){
        for(int i=k-len+1;i<=len-1;i++){
            ans=ans+c[len-1][i];
        }
    } 
    if(lim>k) ans++;
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init();

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}