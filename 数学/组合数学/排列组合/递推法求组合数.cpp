#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int N=5010;
const ll mod=1e9+7;

int n,m;
int C[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    C[0][0]=1;
    for(int i=1;i<=n;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    cout<<C[n][m];
    return 0;
}