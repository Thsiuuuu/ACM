#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
#define ll long long 
#define double long double
#define i128 __int128_t

void sol() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    // bool f=true;
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]){
            cout<<"1\n";
            return ;
        }
    }
    cout<<n<<'\n';
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