#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long
struct node{
    int val,level;
};

void sol() {
    int n;
    cin>>n;
    if(n%2==0){
        cout<<"-1\n";
    }else{
        int tot=log2(n);
        vector<int> ans;
        int cur=n;
        for(int i=0;i<tot;i++){
            int nxt=cur+1;
            if(((nxt)/2)%2==0){
                ans.push_back(2);
                cur=cur/2;
            }else{
                ans.push_back(1);
                cur=(cur+1)/2;
            }
            // cout<<cur<<" ";
        }
        cout<<ans.size()<<'\n';
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }
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