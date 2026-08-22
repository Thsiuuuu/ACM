#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define pll pair<ll,ll>
#define double long double

const int N=1010;
int but[N];

void sol() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];but[a[i]]++;
    }
    int sum=0;
    for(int i=0;i<=1000;i++){
        if(but[i]>i) sum+=but[i]-i;
        else if(but[i]<i) sum+=but[i];
    }
    cout<<sum;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}