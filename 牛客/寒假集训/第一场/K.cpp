#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    cin>>n;
    if(n==1||n==3){
        cout<<"YES\n";
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<'\n';
    }else{
        cout<<"NO\n";
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