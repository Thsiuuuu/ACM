#include <bits/stdc++.h>
using namespace std;
/*



*/

const int N=2050;
int f[N][2];

void sol() {
    int n;
    cin>>n;
    vector<int> a(n+1,0),b(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    for(int i=1;i<=n;i++){
        f[i][0]=max(max(0,f[i-1][0]-a[i]),max(0,f[i-1][1]-a[i]));
        f[i][1]=max(f[i-1][0]^b[i],f[i-1][1]^b[i]);
    }
    cout<<max(f[n][0],f[n][1]);
    
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