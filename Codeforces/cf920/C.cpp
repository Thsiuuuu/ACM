#include <bits/stdc++.h>
using namespace std;
/*

    枚举答案，因为相邻两段不是进行开关机就是一直开着
    所以枚举每一段谁最小就好，注意枚举花费的总时间的等号是不可以的，代表恰好到那里就没电了

*/
#define int long long 
void sol() {
    int n,f,a,b;
    cin>>n>>f>>a>>b;
    vector<int> m(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=(sum+min((m[i]-m[i-1])*a,b));
    }
    cout<<((sum<f)?"Yes":"No")<<'\n';
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