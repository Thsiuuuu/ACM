#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    cin>>n;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i&1) b.push_back(x);
        else a.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        if(i&1) cout<<b[i>>1]<<" ";
        else cout<<a[i>>1]<<" ";
    }
    cout<<'\n';
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