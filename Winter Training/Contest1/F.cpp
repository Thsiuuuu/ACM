#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*



*/
void sol() {
    int sum=0;
    int n;
    cin>>n;
    vector<int> st(n);
    for(int i=0;i<n;i++){
        cin>>st[i];
        sum+=st[i];
    }
    if(sum&1){
        cout<<"Alice\n";
    }else{
        cout<<"Bob\n";
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