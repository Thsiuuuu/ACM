#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='Y') cnt++;
    }
    if(cnt>1){
        cout<<"no\n";
    }else{
        cout<<"yes\n";
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