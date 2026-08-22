#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int ans=0;
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        int sum=a+b+c;
        if(sum<180){
            ans++;
        }
    }
    cout<<ans;
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