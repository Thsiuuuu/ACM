#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
// #define int long long 
#define double long double

const int N=3e5+3;
int f[N][7];

void sol() {
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            f[i][j]=INT32_MAX;
            if(i!=1){
                for(int k=1;k<=6;k++){
                    if(j+k==7||j==k){
                        continue;
                    }
                    f[i][j]=min(f[i][j],f[i-1][k]+((j==a[i])?0:1));
                }
            }
            else f[i][j]=(j==a[i]?0:1);
        }
    }
    int mn=INT32_MAX;
    for(int i=1;i<=6;i++){
        mn=min(f[n][i],mn);
    }
    cout<<mn<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}