#include <bits/stdc++.h>
using namespace std;
/*

    有一种最简单的方法，就是1 1从前向后进行修改
    但是是否有其他方法，换句话说，是否所有的区间修改操作都可以转化为1 1
    手玩样例发现是显然可以的
    所以从头到尾进行修改，每次进行修改之后下一个位置的值一定是一个固定值
    如果修改到最后都无法让两个数列相等的话，就说明没有办法让这两个数列完全相等

*/

#define int long long
void sol() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n-1;i++){
        if(a[i]!=b[i]){
            int del=b[i]-a[i];
            a[i]+=del;
            a[i+1]+=del;
        }
    }
    if(b[n-1]^a[n-1]){
        cout<<"No\n";
    }else{
        cout<<"Yes\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}