#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long
#define double long double 
#define pii pair<ll,ll> 
void sol() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<*max_element(a.begin(),a.end())-*min_element(a.begin(),a.end())+1<<'\n';
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