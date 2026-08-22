#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>


/*

    因为这道题要求多次访问的最大值，考虑用大顶堆存储，可以动态调整
    然后是延迟删除技巧，因为这里我们不知道堆顶是不是需要被删除的
    所以删除某一个元素很麻烦，这里我们并不直接删除，而是把他标为无效
    如何标为无效，这里考虑用一个哈希表进行标记，当哈希值为0的时候，他确实是被删除干净了


*/

using namespace std;

int n,x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>x>>n;

    set<int> street;
    street.insert(0);
    street.insert(x);

    priority_queue<int> pq;
    pq.push(x);

    //延迟删除
    unordered_map<int,int> count;
    count[x]=1;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        

        auto it=street.lower_bound(t);
        int r=*it;
        int l=*prev(it);

        street.insert(t);
        int old=r-l;
        int newl=t-l;
        int newr=r-t;

        count[old]--;

        pq.push(newl),pq.push(newr);
        count[newl]++,count[newr]++;

        while(!pq.empty()&&count[pq.top()]==0){
            pq.pop();
        }

        cout<<pq.top()<<(i==n-1?'\n':' ');
    }
    return 0;

}