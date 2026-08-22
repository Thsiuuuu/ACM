#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
// #define int long long 
#define double long double
void sol() {
    int n;
    cin>>n;
    bool f=false;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==67&&(!f)){
            cout<<"YES\n";
            // return ;
            f=true;            
        }
    }
    if(f) return ;
    cout<<"NO\n";
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