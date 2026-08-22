#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 

const  int N=1e5+10;
ll f[N][26];

void sol() {
    int n,m,k;
    cin>>n>>k>>m;
    vector<ll> a(n+1,0),pre(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    
        for(int j=0;j<=k+1;j++){
            f[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++){
        f[i][0]=max(f[i][0],max(f[i-1][0],f[i-1][1])+a[i]);
        f[i][k+1]=max(f[i][k+1],max(f[i-1][0],f[i-1][1])+2*a[i]);
        for(int j=1;j<=k;j++)  f[i][j]=max(f[i][j],f[i-1][j+1]+a[i]/2);
        for(int j=0;j<=k+1;j++) f[min(n,i+m)][max(0,j-m-1)]=max(f[min(n,i+m)][max(0,j-m-1)],f[i-1][j]+pre[min(i+m,n)]-pre[i-1]);
    }

    cout<<*max_element(f[n],f[n]+k+2)<<'\n';
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