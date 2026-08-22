#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node{
    int lst,idx;
    int pick;

    bool st=false;


    bool operator<(const node&other)const{
        return pick>other.pick;
    }
};



void sol(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<node> blue,red,all;
    priority_queue<node> que;
    int blst=-1,rlst=-1;
    for(int i=0;i<n;i++){
        int j=i;
        int mx=-1ll;
        while(j<n&&s[j]=='B'){
            mx=max(mx,a[j]);
            j++;
        }
        if(j>i){
            blue.push_back({blst,blue.size(),mx});
            all.push_back({blst,all.size(),mx});
            que.push({blst,blue.size()-1,mx});
            mx=-1,blst=j-1;
        }
        while(j<n&&s[j]=='R'){
            mx=max(mx,a[j]);
            j++;
        }
        if(j>i){
            red.push_back({rlst,rlst.size(),mx});
            all.push_back({rlst,all.size(),mx});
            mx=-1,rlst=j-1;
        }
        i=j-1;
    }
    if(blue.size()<=k){
        cout<<"0\n";
    }else{
        int cnt=0;
        while(cnt<=k){
            auto[lst,idx,pick]=que.top();
            que.pop();
            blue[idx].st=true;
        }
    }
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