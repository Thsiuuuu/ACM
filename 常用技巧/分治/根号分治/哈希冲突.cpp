#include <bits/stdc++.h>
using namespace std;
/*

    今天也是入门根号分治啦
    https://www.luogu.com.cn/problem/P3396

    根号分治相当于以sqrt(n)进行划分，规模大的最多不超过sqrt(n)次解决，规模小的通过预处理进行解决

    这道题就是分别记录mod p，p<=sqrt(n)情况下的数组的和

    2026年1月28日 腊月初十 23:20:15

*/
#define int long long 
const int N=2e3;
int val[N][N];
void sol() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    int blk=sqrt(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=blk;j++){
            val[j][i%j]+=a[i];
        }
    }
    while(m--){
        char op;
        cin>>op;
        int x,y;
        cin>>x>>y;
        if(op=='A'){
            if(x>blk){
                int sum=0;
                for(int i=y;i<=n;i+=x){
                    if(i%x==y){
                        sum+=a[i];
                    }
                }
                cout<<sum<<'\n';
            }else{
                cout<<val[x][y]<<'\n';
            }
        }else{
            for(int j=1;j<=blk;j++){
                val[j][x%j]+=(y-a[x]);
            }
            a[x]=y;
        }
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