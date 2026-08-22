#include <bits/stdc++.h>
using namespace std;
/*



*/
#define double long double
void sol() {
    double k;
    cin>>k;
    double c=k-273.15;
    double f=c*1.8+32;
    cout<<f;
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