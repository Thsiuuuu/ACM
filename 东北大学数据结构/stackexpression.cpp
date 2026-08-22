#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

typedef pair<string,int>  PSI;


int main(){
    
    int n,q;
    cin>>n>>q;
    vector<pair<string,int>> pro(n);
    for(int i=0;i<n;i++) cin>>pro[i].first>>pro[i].second;

    queue<pair<string,int>> que;
    for(int i=0;i<n;i++)  que.push(pro[i]);
    while(!que.empty()){
        PSI fro=que.front();
        fro.second-=q;
        que.pop();
        if(fro.second>0) que.push(fro);
        else cout<<fro.first<<" "<<fro.second<<"\n";
    }

    
    return 0;
}