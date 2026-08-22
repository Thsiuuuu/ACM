#include <bits/stdc++.h>
using namespace std;
/*

    高维前缀和进行转移

    手玩可以发现a_j&a_i=0，则a_i按位取反之后,a_j是它的子集
    所以可以对值域做高维前缀和

    根据子集dp的转移方程f(sta,i)=(f(sta,i-1))∪(f(sta^(2^i),i-1))[sta&(1<<i)==1]
    就从小到大去维护每个集合里面有没有数就可以

*/

const int N=1<<22;
int f[N+1];

void sol() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    memset(f,-1,sizeof(f));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[a[i]]=a[i];
    }
    for(int i=0;i<=21;i++){
        for(int j=0;j<=N-1;j++){
            if((j&(1<<i))&&(f[j^(1<<i)]!=-1)){
                f[j]=f[j^(1<<i)];
            }
        }
    }
    int mask=(1<<22)-1;
    for(int i=1;i<=n;i++){
        cout<<f[a[i]^mask]<<" ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}