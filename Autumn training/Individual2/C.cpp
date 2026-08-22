#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*


    比赛时候猜出来不超过3了，但是不知道怎么判断
    对于每次变化可以尝试用数学上的语言描述
    可以发现，对于k=2的情况，每次交换之后都是一个环状的东西，所以k=2可行一定是两个连续的递增的区间
    对于其余的空间，可以先找到1，然后通过交换和2的起始位置，再进行一次交换，得到1,2，...的序列
    以此类推，对任意的序列，总可以以这样的方式进行构造。

    主要卡在k=2的证明上了，如果大胆的采用数学的语言进行描述交换后的结果就可以发现k=2什么时候可行了
    k=3是没有多手玩


*/
void sol(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int num=0;
    for(int i=0;i<n-1;i++){
        if(a[i]+1!=a[i+1]) num++;
    }
    if(num<2){
        cout<<num+1;
    }else cout<<3;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}