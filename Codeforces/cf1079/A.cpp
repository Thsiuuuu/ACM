#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long
void sol() {
    ll n;
    cin>>n;
    // if(n%9==0){
    //     cout<<"10\n";
    // }else{
    //     cout<<"0\n";
    // }

    int ans=0;
    for(int d=0;d<=83;d++){
        ll y=n+d;
        string s=to_string(y);
        int sum=0;
        for(int i=0;i<s.size();i++) sum+=s[i]-'0';
        if(sum==d) ans++;
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