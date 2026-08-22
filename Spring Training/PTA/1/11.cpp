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

const int N=1e5+2;
vector<int> e[N],ans,all;
int root;

void dfs(int u){
    ans.push_back(u);
    if(e[u].size()==0) return ;
    sort(e[u].begin(),e[u].end());
    for(int v:e[u]) dfs(v);
}

void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int fa;cin>>fa;
        if(!fa) root=i;
        else e[fa].push_back(i);
    }
    for(int i=1;i<=n;i++) all.push_back((int)e[i].size());
    sort(all.begin(),all.end(),greater<int>());
    all.erase(unique(all.begin(),all.end()),all.end());
    dfs(root);
    cout<<all[0]<<" ";
    cout<<((all.size()>2)?"no":"yes")<<'\n';
    for(int i=0;i<ans.size();i++){
        if(i) cout<<" ";
        cout<<ans[i];
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