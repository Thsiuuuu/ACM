#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long 

struct node{
    string s1,s2;
    bool operator<(const node&other)const{
        if(s1==s2) return s2<other.s2;
        return s1<other.s1;
    }
};

void sol(){
    priority_queue<string,vector<string>,greater<string>> q;
    int n;
    cin>>n;
    int ans=0;
    vector<node> all(n);
    for(int i=0;i<n;i++){
        cin>>all[i].s1>>all[i].s2;
    } 
    sort(all.begin(),all.end());;
    for(int i=0;i<n;i++){
        auto[s1,s2]=all[i];
        if(!q.size()||s1<=q.top()){
            ans++;
        }else{
            q.pop();
        }
        q.push(s2);
    }
    cout<<ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}