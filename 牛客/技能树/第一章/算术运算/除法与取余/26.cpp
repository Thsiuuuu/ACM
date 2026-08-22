#include <bits/stdc++.h>
using namespace std;
/*

https://www.nowcoder.com/practice/c4ae7bcac7f9491b8be82ee516a94899?channelPut=tracker3

*/
void sol() {
    int s,h,m;
    cin>>s;
    m=s/60;
    s=s%60;
    h=m/60;
    m=m%60;
    cout<<h<<" "<<m<<" "<<s;
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