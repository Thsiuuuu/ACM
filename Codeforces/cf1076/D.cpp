#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long
void sol() {
    int n;
    cin>>n;
    vector<int> a(n+1,0),b(n+1,0),pre(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        pre[i]=pre[i-1]+b[i];
    }
    sort(a.begin()+1,a.end());
    int number=n,cur=1;
    int ans=0;
    for(int i=1;i<=n;i++){
        while(cur<=n&&a[cur]<a[i]){
            cur++;
            number--;
        }
        auto it=upper_bound(pre.begin(),pre.end(),number);
        int dis=it-pre.begin()-1;
        ans=max(ans,a[i]*dis);
    }
    cout<<ans<<'\n';
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