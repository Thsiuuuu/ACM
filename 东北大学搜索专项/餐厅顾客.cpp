#include <iostream>
#include <algorithm>
#include <vector>

/*
    扫描线算法

    将每个顾客的进店和出店看成两个独立事件
    然后进行排序
    遍历事件而不是遍历区间，有效降低时间复杂度
*/

using namespace std;

typedef pair<int,int> pii;

bool cmp(pii a,pii b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}



signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    vector<pii> cust;
    int n;

    cin>>n;
    for(int i=0;i<n;i++){
        
        int a,b;
        cin>>a>>b;
        cust.emplace_back(a,1);
        cust.emplace_back(b,-1);

    }

    sort(cust.begin(),cust.end(),cmp);
    
    int mx=0,cur=0;

    for(const auto&man:cust){
        cur+=man.second;
        mx=max(cur,mx);
    }

    cout<<mx;
    return 0;

}
