#include <bits/stdc++.h>
using namespace std;

#define int long long 
struct node{
    int u,dis;
    // bool operator<(const node&a){
    //     return dis>a.dis;
    // }
};
struct cmp{
    bool operator()(const node&a,const node&b){
        return a.dis<b.dis;
    }
};
void sol(){
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> a(n);
    set<int> st;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    
    priority_queue<node,vector<node>,cmp> que;
    for(int i=1;i<n;i++){
        if((a[i]-a[i-1])&1){
            if(st.find((a[i]+a[i-1])/2)==st.end()){
                que.push({(a[i]+a[i-1])/2,(a[i]+a[i-1])/2-a[i-1]});
                st.insert((a[i]+a[i-1])/2);
            }
            if(st.find(1+(a[i]+a[i-1])/2)==st.end()){
                que.push({1+(a[i]+a[i-1])/2,(a[i]+a[i-1])/2-a[i-1]});
                st.insert(1+(a[i]+a[i-1])/2);
            }
        }else{
            if(st.find((a[i]+a[i-1])/2)==st.end()){
                que.push({(a[i]+a[i-1])/2,(a[i]+a[i-1])/2-a[i-1]});
                st.insert((a[i]+a[i-1])/2);
            }
        }
    }
    if(a[0]>0){
        que.push({0,a[0]});
        st.insert(0);
    }
    if(a[n-1]<x){
        que.push({x,x-a[n-1]});
        st.insert(x);
    }
    // for(int u:st) cout<<u<<" ";
    // cout<<'\n';
    // int ans=0;
    vector<int> res;
    while(k--){
        auto[u,dis]=que.top();
        que.pop();
        // cout<<k<<'\n'<<u<<" "<<dis<<"\n";
        // ans+=dis;
        res.push_back(u);
        // if(dis==0){
        //     continue;
        // }
        if((u-1)>=0&&st.find(u-1)==st.end()){
            st.insert(u-1);
            que.push({u-1,dis-1});
        }
        if((u+1)<=x&&st.find(u+1)==st.end()){
            st.insert(u+1);
            que.push({u+1,dis-1});
        }
    }
    // cout<<ans<<'\n';
    for(int u:res) cout<<u<<" ";
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}