#include <bits/stdc++.h>
using namespace std;

bool cmp1(int a,int b){
    return a>b;
}

struct cmp{
    bool operator()(int a,int b){
        return a>b;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end(),cmp1);

    priority_queue<int,vector<int>,cmp> que;
    for(int i=0;i<n;i++){
        que.push({arr[i]});
    }
    while(!que.empty()){
        cout<<que.top()<<" ";
        que.pop();
    }
    cout<<'\n';

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}