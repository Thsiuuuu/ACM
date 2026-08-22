#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    ll m,n,z;
    cin>>m>>n>>z;
    if(z%(m+n)>0&&z%(m+n)<=m){
        cout<<"0";
    }else{
        cout<<"1";
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