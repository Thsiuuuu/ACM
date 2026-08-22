#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long
#define double long double 
#define pii pair<ll,ll>


void sol() {
    int n,m;
    cin>>n>>m;
    int a=min(n,m),b=max(n,m);
    if(a==1){
        cout<<b/2+1<<'\n';
    }else{
        cout<<a+(b-a+1)/2<<'\n';
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