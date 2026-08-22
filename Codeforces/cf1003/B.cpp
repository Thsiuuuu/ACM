#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    string s;
    cin>>s;
    s=' '+s;
    for(int i=1;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            cout<<"1\n";
            return ;
        }
    }
    cout<<s.size()-1<<'\n';
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