#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
void sol() {
    int n,t;
    cin>>n>>t;
    vector<int> tm(n);
    for(int i=0;i<n;i++){
        cin>>tm[i];
    }
    if(tm.size()==0||tm[n-1]!=t){
        tm.push_back(t);
    }

    int sum=0;
    int cur=0ll;
    while(cur<=t){
        auto it=lower_bound(tm.begin(),tm.end(),cur);
        if(it!=tm.end()){
            sum+=(*it-cur);
        }
        cur=*it+100;
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