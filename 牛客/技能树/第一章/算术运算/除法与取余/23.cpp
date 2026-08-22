#include <bits/stdc++.h>
using namespace std;
/*

https://www.nowcoder.com/practice/031db23916904f4fad72198fe491b47b?channelPut=tracker3

*/
void sol() {
    string s;
    cin>>s;
    if(s.size()>=2){
        reverse(s.begin(),s.end());
        cout<<s[1];
    }else{
        cout<<"0";
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