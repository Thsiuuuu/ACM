#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int x,n;
    cin>>x>>n;
    n=n%7;
    x=x+n;
    if(x>7){
        cout<<x-7;
    }else cout<<x;
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