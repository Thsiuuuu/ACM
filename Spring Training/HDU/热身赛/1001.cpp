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

    vector<int> ans;
    ans.push_back(1);
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            if(i==2) ans.push_back(2);
            else{
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }
    }
    sort(ans.begin(),ans.end(),greater<int>());
    cout<<ans[0]<<'\n';
    
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