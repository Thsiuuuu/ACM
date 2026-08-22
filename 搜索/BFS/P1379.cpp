#include <bits/stdc++.h>
using namespace std;
struct node{
    string s;
    int idx;
    int level;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    string obj="123804765";
    string ori;
    cin>>ori;
    queue<node> que;
    que.push({ori,(int)ori.find('0'),0});
    map<string,int> mp;
    mp[ori]=1;
    while(que.size()){
        auto[s,idx,level]=que.front();
        que.pop();
        if(s==obj){
            cout<<level;
            return 0;
        }else{
            if(idx<=5){
                string nx=s;
                swap(nx[idx],nx[idx+3]);
                if(mp.find(nx)==mp.end()){
                    que.push({nx,idx+3,level+1});    
                    mp[nx]=1;
                }
            }
            if(idx>=3){
                string nx=s;
                swap(nx[idx],nx[idx-3]);
                if(mp.find(nx)==mp.end()){
                    que.push({nx,idx-3,level+1});
                    mp[nx]=1;
                }
            }
            if(idx!=0&&idx!=3&&idx!=6){
                string nx=s;
                swap(nx[idx],nx[idx-1]);
                if(mp.find(nx)==mp.end()){
                    que.push({nx,idx-1,level+1});
                    mp[nx]=1;
                } 
            }
            if(idx!=2&&idx!=5&&idx!=8){
                string nx=s;
                swap(nx[idx],nx[idx+1]);
                if(mp.find(nx)==mp.end()){
                    que.push({nx,idx+1,level+1});
                    mp[nx]=1;
                }
            }
        }
    }
}