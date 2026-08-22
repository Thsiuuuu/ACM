#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
#define ll long long 
#define double long double
#define i128 __int128_t

void sol() {
    stack<char> q;
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(!q.size()) q.push(s[i]);
        else{
            if(q.top()==s[i]) q.pop();
            else q.push(s[i]);
        }
    }
    if(q.size()) cout<<"NO\n";
    else cout<<"YES\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}