#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
#define ll long long 
#define double long double
#define i128 __int128_t
#define pii pair<int,int>

void sol() {
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(n+1),b;
    deque<int> ans;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i<=x||i>y){
            b.push_back(a[i]);
        }
    }
    int curmin=x+1;
    for(int i=curmin;i<=y;i++){
        if(a[i]<a[curmin]) curmin=i;
    }
    for(int i=curmin,cnt=0;cnt<y-x;cnt++){
        ans.push_back(a[i]);
        i++;
        if(i>y) i=x+1;
    }
    int tk=-1;
    for(int i=0;i<b.size();i++){
        if(b[i]<a[curmin]){
            // ans.push_front(b[i]);
            // cout<<b[i]<<" ";
            tk=i;
        }else{
            break;
            // for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
            // while(i<b.size()){
            //     cout<<b[i]<<" ";
            //     // ans.push_back(b[i]);
            //     i++;
            // }
        }
    }
    for(int i=0;i<=tk;i++){
        cout<<b[i]<<" ";
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    for(int i=tk+1;i<b.size();i++){
        cout<<b[i]<<" ";
    }
    // for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
    // cout<<'\n';
    // cout<<a[curmin]<<'\n';
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
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