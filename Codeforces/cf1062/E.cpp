#include <bits/stdc++.h>
using namespace std;

#define int long long 


void sol(){
    int n,k,x;
    cin>>n>>k>>x;
    stack<int> ans;
    queue<pair<int,int>> que;
    set<int> st;
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        que.push({l,0});
        st.insert(l);
    }
    while(que.size()){
        auto [u,dis]=que.front();
        ans.push(u);
        que.pop();
        if(u+1<=x&&st.find(u+1)==st.end()){
            st.insert(u+1);
            que.push({u+1,dis+1});
        }else if(u-1>=0&&st.find(u-1)==st.end()){
            st.insert(u-1);
            que.push({u-1,dis+1});
        }
    }
    for(int i=0;i<k;i++){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}