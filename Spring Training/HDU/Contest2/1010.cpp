#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define double long double
#define i128 __int128_t
#define ull unsigned long long  

vector<int> res;

void dfs(int x,ll k){
    if(k==0) return ;
    // cout<<x<<" "<<k<<'\n';
    for(int i=1;i<=x;i++){
        ll tmp;
        tmp=((x-i<=62)?((1ll<<(x-i))):(INT64_MAX));
        if(k<=tmp){res.push_back(i);x-=i;k--;break;}
        else k-=tmp;
    }
    dfs(x,k);
}



void sol() {
    int x;ll k;cin>>x>>k;
    dfs(x,k);
    for(auto i:res) cout<<i<<" ";
    cout<<'\n';
    res.clear();
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