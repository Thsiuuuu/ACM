#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

    4 8
3 4 1 8
4 7 1 8 4
5 6 5 1 2 3
4 3 2 4 8
*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  

void sol() {
    int n,m;cin>>n>>m;
    vector<set<int>> tot(m+1);
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int x;cin>>x;
            tot[x].insert(i);
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(auto&x:tot[i]) cout<<x<<" ";
    //     cout<<'\n';
    // }
    int q;cin>>q;
    while(q--){
        int x,y;cin>>x>>y;
        set<int> st;st=tot[x];
        for(auto num:tot[y]) st.insert(num);
        // cout<<tot[x].size()<<" "<<tot[y].size()<<" ";
        // cout<<st.size()<<'\n';
        // for(auto &num:st) cout<<num<<" ";
        // cout<<'\n';
        cout<<(int)tot[x].size()+(int)tot[y].size()-(int)st.size()<<'\n';
    }   
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