#include <bits/stdc++.h>
using namespace std;
/*



*/

#define int long long 
void sol() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    
    a.erase(unique(a.begin(),a.end()),a.end());
    int mx=1;
    for(int i=0;i<n;i++){
        int j=i;
        int len=1;
        while(j+1<n&&a[j]+1==a[j+1]){
            len++;
            mx=max(mx,len);
            j++;
        }
        i=j;
    }
    cout<<mx<<'\n';
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