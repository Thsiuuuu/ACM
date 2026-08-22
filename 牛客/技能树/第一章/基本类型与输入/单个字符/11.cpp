#include <bits/stdc++.h>
using namespace std;
/*


https://www.nowcoder.com/practice/2dbf0151eb71402e968a2a8e59092568?channelPut=tracker3
*/
void sol() {
    char c;
    cin>>c;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cout<<c;
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