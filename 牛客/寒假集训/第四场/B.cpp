#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
void sol() {
    int n,q,s;
    cin>>n>>q>>s;
    vector<int> a(n),t(n);
    a[0]=s;
    for(int i=0;i<n;i++){
        cin>>t[i];
        if(i){
            a[i]=a[i-1]+t[i-1];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<a[x-1]+y-1<<'\n';
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