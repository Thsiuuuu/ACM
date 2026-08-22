#include <bits/stdc++.h>
using namespace std;

/*
    从1出发
    1.*10,代价为0
    2.+1,代价为1
    如果出现了19->20这种可以通过2->20得到，通过01bfs可以被正确的更新
*/

const int N=1e5+10;
bool vis[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int k;
    cin>>k;

    deque<pair<int,int>> q;
    q.push_back({1,1});
    while(q.size()){
        auto [number,cost]=q.front();
        q.pop_front();
        if(vis[number]) continue;
        vis[number]=1;
        if(!number){
            cout<<cost;
            return 0;
        }
        q.push_front({(number*10)%k,cost});
        q.push_back({(number+1)%k,cost+1});
    }
    
}