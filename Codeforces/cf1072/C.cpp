#include <bits/stdc++.h>
using namespace std;
/*



*/
struct node{
    int cur;
    int level;
};
void sol() {
    int n,k;
    cin>>n>>k;
    if(n<k){
        cout<<"-1\n";
        return ;
    }
    queue<node> que;
    que.push({n,0});
    map<int,int> mp;
    int ans=-1;
    while(que.size()){
        auto[cur,level]=que.front();
        // cout<<cur<<" "<<level<<'\n';
        que.pop();
        if(cur==k){
            ans=level;
            break ;
        }
        if(cur/2>0&&mp.find(cur/2)==mp.end()){
            que.push({cur/2,level+1});
            mp[cur/2]=1;
        }
        if((cur&1)&&(cur/2)>0){
            // cout<<cur<<" "<<level<<'\n';
            if(mp.find(cur/2+1)==mp.end()){
                que.push({cur/2+1,level+1});
                mp[cur/2+1]=1;
            }
        }
    }  
    cout<<ans<<'\n';
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