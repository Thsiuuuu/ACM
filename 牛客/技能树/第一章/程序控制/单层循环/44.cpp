#include <bits/stdc++.h>
using namespace std;
/*



*/
#define double long double
void sol() {
    double sum=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        sum=sum+(1.0)/i;
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