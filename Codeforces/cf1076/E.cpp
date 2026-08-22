#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    vector<int> vis(n+1,0);
    for(int i=0;i<a.size();i++){
        vis[a[i]]=1;
    }
    vector<int> dp(n+1,-1);
    for(int i=1;i<=n;i++){
        if(vis[i]){
            dp[i]=1;
        }else{
            for(int number=1;number*number<=i;number++){
                if(i%number==0){
                    // cout<<i<<" "<<number<<'\n';
                    int famber=i/number;
                    if(vis[famber]&&vis[number]){
                        vis[i]=1;
                        if(dp[i]==-1){
                            dp[i]=dp[famber]+dp[number];
                        }else{
                            dp[i]=min(dp[i],dp[famber]+dp[number]);
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<'\n';
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