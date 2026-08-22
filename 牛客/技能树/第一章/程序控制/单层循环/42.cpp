#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
    }
    cout<<sum;
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