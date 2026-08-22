#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int number=*max_element(a.begin(),a.end());
    if(a[0]==number||a[n-1]==number){
        cout<<(ll)(n-1)*number+(ll)min(a[0],a[n-1])<<'\n';
    }else{
        cout<<(ll)(n-2)*number+(ll)a[0]+(ll)a[n-1]<<'\n';
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