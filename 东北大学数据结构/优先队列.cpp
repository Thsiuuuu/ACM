#include <iostream>
#include <queue>
#include <string>
#include <algorithm>


using namespace std;

#define int long long
#define endl "\n";

signed main(){
    priority_queue<int> pq;
    string op;
    while(cin>>op){
        if(op=="insert"){
            int k;
            cin>>k;
            pq.push(k);
        }else if(op=="extract"){
            if(!pq.empty()){
                cout<<pq.top()<<endl;
                pq.pop();
            }
        }else break;
    }
    return 0;
}