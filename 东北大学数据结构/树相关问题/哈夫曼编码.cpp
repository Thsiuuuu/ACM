#include <bits/stdc++.h>
using namespace std;

struct node{
    int val=0;
    char name='*';
    int idx;
    int left=-1,right=-1;
    
    bool operator<(const node&others)const{
        return val>others.val;
    }

};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    string s;
    cin>>s;
    vector<node> vec(27);
    for(int i=0;i<s.size();i++){
        vec[s[i]-'a'].val++;
    }
    int number=0;
    for(int i=0;i<27;i++){
        if(vec[i].val) number++;
    }
    if(number==1){
        cout<<s.size();
        return 0;
    }
    priority_queue<node,vector<node>> que;
    map<int,node> mp;
    int tot=0;
    for(int i=0;i<27;i++){
        if(vec[i].val>0){
            vec[i].idx=++tot;
            vec[i].name='a'+i;
            que.push(vec[i]);
            mp[tot]=vec[i];
        }
    }
    while(que.size()>1){
        node ls=que.top();
        que.pop();
        node rs=que.top();
        que.pop();
        node nw;
        nw.idx=++tot;
        nw.val=ls.val+rs.val;
        nw.left=ls.idx,nw.right=rs.idx;
        que.push(nw);
        mp[tot]=nw;
    }
    vector<int> cnt(27,0);
    queue<pair<node,int>> q;
    q.push({que.top(),0});
    while(q.size()){
        auto [cur,level]=q.front();
        q.pop();
        if(cur.name!='*'){
            cnt[cur.name-'a']=level;
        }
        if(cur.left!=-1){
            q.push({mp[cur.left],level+1});
        }
        if(cur.right!=-1){
            q.push({mp[cur.right],level+1});
        }
    }
    int ans=0;
    for(int i=0;i<s.size();i++){
        ans+=cnt[s[i]-'a'];
    }
    cout<<ans;
    
    return 0;
}