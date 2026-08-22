#include <bits/stdc++.h>
using namespace std;
/*

    一个人对另外一个人的作用只存在于他们有好友的时候，区间加和问题可以转化成前缀和
    在建立好友的时候减掉当前贡献，在解除好友的时候加上当前贡献

    可以反过来考虑，因为反过来相当于解除和建立都是完全对应的，不需要用set存储最后还有哪些人有好友关系

*/
void sol() {
    int n,m;
    cin>>n>>m;
    vector<int> cnt(n+1,0),ans(n+1,0);
    vector<set<int>> st(n+1);
    for(int i=1;i<=m;i++){
        char op;
        cin>>op;
        
        if(op=='!'){
            int x;
            cin>>x;
            cnt[x]++;
        }else if(op=='+'){
            int x,y;
            cin>>x>>y;
            ans[x]-=cnt[y];
            ans[y]-=cnt[x];
            st[x].insert(y);
            st[y].insert(x);
        }else{
            int x,y;
            cin>>x>>y;
            ans[x]+=cnt[y];
            ans[y]+=cnt[x];
            st[x].erase(y);
            st[y].erase(x);
        }
    }
    for(int x=1;x<=n;x++){
        for(int y:st[x]){
            ans[x]+=cnt[y];
            // ans[y]-=cnt[x];
            // st[x].erase(y);
            // st[y].erase(x);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}