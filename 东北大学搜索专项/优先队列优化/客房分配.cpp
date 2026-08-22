#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
    考虑用优先队列进行维护离开时间的最小值
    然后模拟即可
*/


struct cust
{
    int start;
    int leave;
    int idx;
    /* data */
};


bool cmp(const cust& a,const cust& b){
    if(a.start==b.start) return a.leave<b.leave;
    return a.start<b.start;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n;
    cin>>n;
   
    vector<cust> buyer(n);
    for(int i=0;i<n;i++){
        cin>>buyer[i].start>>buyer[i].leave;
        buyer[i].idx=i;
    }

    sort(buyer.begin(),buyer.end(),cmp);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> room(n);

    int cnt=0;
    for(const auto& man:buyer){
        if(pq.empty()||man.start<=pq.top().first){
            cnt++;
            pq.emplace(man.leave,cnt);
            room[man.idx]=cnt;
        }else{
            auto [pre,number]=pq.top();
            pq.pop();
            pq.emplace(man.leave,number);
            room[man.idx]=number;
        }
    }

    cout<<cnt<<"\n";
    for(int num:room){
        cout<<num<<" ";
    }

    return 0;

}