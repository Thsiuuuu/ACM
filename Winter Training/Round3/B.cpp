#include <bits/stdc++.h>
using namespace std;
/*

    反悔贪心
    按照时间进行排序，如果枚举的物品的截止时间发生在了当前的时间及其之间，并且价值比堆底的价值更优，就说明这个物品应该在里面
    否则直接放进去并添加时间就可以

*/

#define int long long 
// struct node{
//     int t,val;
//     bool operator<(const node&other)const{
//         if(t==other.t) return val<other.val;
//         else return t>other.t;
//     }
// };

struct node{
    int t,val;
    bool operator<(const node&other)const{
        if(t==other.t) return val<other.val;
        return t<other.t;
    }
};

void sol() {
    
    // priority_queue<node> que;
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> que;
    vector<node> tk(n);
    for(int i=0;i<n;i++){
        cin>>tk[i].t>>tk[i].val;
    }
    sort(tk.begin(),tk.end());
    int ans=0ll;
    int t=0;
    for(int i=0;i<n;i++){
        if(tk[i].t<=t){
            if(tk[i].val>que.top()){
                que.pop();
                que.push(tk[i].val);
            }
        }else{
            que.push(tk[i].val);
            t++;
        }
    }
    while(que.size()){
        ans+=que.top();
        que.pop();
    }
    cout<<ans<<'\n';
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