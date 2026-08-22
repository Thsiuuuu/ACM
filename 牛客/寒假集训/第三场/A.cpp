#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int x;
    cin>>x;
    for(int i=1;i<=100;i++){
        if(i*(i+1)==x){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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