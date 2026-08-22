#include <bits/stdc++.h>
using namespace std;
/*

    https://www.nowcoder.com/practice/85ef91cfe5a6417ba0e9ba6908ef1868?channelPut=tracker3
*/

void sol() {
    for(int i=1;i<=2;i++){
        for(int j=1;j<=12;j++){
            if(j==6||j==7) cout<<'*';
            else cout<<' ';
        }
        cout<<'\n';
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=12;j++){
            cout<<'*';
        }
        cout<<'\n';
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=12;j++){
            if(j==5||j==8) cout<<'*';
            else cout<<' ';
        }
        cout<<'\n';
    }
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