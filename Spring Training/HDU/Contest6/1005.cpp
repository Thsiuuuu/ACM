#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
void sol() {
    int n,k;
    cin>>n>>k;
    stack<pii> stk;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(stk.size()==0||stk.top().first!=x) stk.push({x,1});
        else if(stk.top().second!=k-1) stk.push({x,stk.top().second+1});
        else{
            while(stk.size()&&stk.top().first==x){
                stk.pop();
            }
        }
    }
    vector<int> res;
    while(stk.size()){
        res.push_back(stk.top().first);
        stk.pop();
    }
    cout<<res.size()<<'\n';
    reverse(res.begin(),res.end());
    for(int x:res) cout<<x<<" ";
    cout<<'\n';
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