#include <bits/stdc++.h>
using namespace std;
/*



*/

const int N=1e3+10;
int sum[N];
void sol() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        sum[i]+=sum[i-1];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int tot=sum[a[i]];
        if(5*(tot-1)>=4*(n-1)){
            ans+=a[i];
        }
    }
    cout<<ans;
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