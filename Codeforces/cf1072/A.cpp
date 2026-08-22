#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    cin>>n;
    if(n==2){
        cout<<"2\n";
    }else if(n==3){
        cout<<"3\n";
    }else{
        if(n&1){
            cout<<"1\n";
        }else{
            cout<<"0\n";
        }
    }
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