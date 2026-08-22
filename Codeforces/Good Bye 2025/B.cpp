#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(i==0&&s[i]=='u'){
            s[i]='s';
            ans++;
        }
        if(s[i]=='u'){
            if(s[i+1]=='u'){
                s[i+1]='s';
                ans++;
            }
        }        
    }
    if(s[s.size()-1]=='u'){
        ans++;
    }
    cout<<ans<<'\n';
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