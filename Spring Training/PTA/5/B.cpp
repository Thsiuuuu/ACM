#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
#define i128 __int128_t






int tr[120],n,idx=0;
void dfs(int i){
    if(i>n) return ;
    dfs(i<<1);
    dfs(i<<1|1);
    tr[i]=++idx;
}

void sol(){
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    for(int i=1;i<=n;i++){
        if(i>1) cout<<" ";
        cout<<a[tr[i]];
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}