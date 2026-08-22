#include <bits/stdc++.h>
using namespace std;
/*

https://www.nowcoder.com/practice/11a5040fa894430f9d25fda1be37ddc8?channelPut=tracker3

*/
void sol() {
    char x;
    cin>>x;
    cout<<"  "<<x<<"  \n";
    cout<<" "<<x<<x<<x<<" \n";
    for(int i=1;i<=5;i++){
        cout<<x;
    }
    cout<<'\n';
    cout<<" "<<x<<x<<x<<" \n";
    cout<<"  "<<x<<"  \n";
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