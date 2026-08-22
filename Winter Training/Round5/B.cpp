#include <bits/stdc++.h>
using namespace std;
/*

    不存在一个非空子集，按位异或起来为0，可以想到线性基
    因为线性基就是没有异或和为0的子集
    然后需要找到最大，那么可以对价值从大到小排序，贪心
    为什么贪心是正确的，因为如果当前有一个元素放进来使得出现为0的子集，它的价值一定是构成当成异或和为0的组合的物品中价值最小的
    它换掉谁都会导致总价值降低

    所以采用贪心法插入线性基就可以

*/
#define int long long 
struct node{
    int number,val;
    bool operator<(const node&other)const{
        return val>other.val;
    }
};


void sol() {
    int n;
    cin>>n;
    vector<node> stone(n);
    for(int i=0;i<n;i++){
        cin>>stone[i].number>>stone[i].val;
    }  
    sort(stone.begin(),stone.end());
    int ans=0;

    vector<int> p(64,0);
    for(int i=0;i<n;i++){
        for(int j=63;~j;j--){
            if(!(stone[i].number>>j)){
                continue;
            }
            if(!p[j]){
                ans+=stone[i].val;
                p[j]=stone[i].number;
                break;
            }
            stone[i].number^=p[j];
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}