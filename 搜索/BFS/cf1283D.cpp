#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;

    set<int> st,ans;
    queue<pair<int,int>> que;
    int siz=0,sum=0;
    for(int i=0,x;i<n;i++){
        cin>>x;
        st.insert(x);
        que.push({x,0});
    }
    while(siz<m){
        auto [u,dis]=que.front();
        que.pop();
        if(st.find(u+1)==st.end()){
            que.push({u+1,dis+1});
            st.insert(u+1);
            ans.insert(u+1);
            sum+=dis+1;
            siz++;
        }
        if(siz==m) break;
        if(st.find(u-1)==st.end()){
            que.push({u-1,dis+1});
            st.insert(u-1);
            ans.insert(u-1);
            sum+=dis+1;
            siz++;
        }
    }
    cout<<sum<<'\n';
    for(int u:ans) cout<<u<<" ";
    return 0;
}