#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    string s,f;
    cin>>n>>s>>f;
    int num1=0,num2=0;
    for(int i=0;i<s.size();i++){
        if(s[i]^f[i]){
            if(s[i]=='0') num1++;
            else num2++;
        }
    }
    cout<<min(num1,num2)+abs(num1-num2)<<'\n';
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