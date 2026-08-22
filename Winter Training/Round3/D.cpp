#include <bits/stdc++.h>
using namespace std;
/*

    使用单调队列进行优化
    首先是状态转移方程怎么列
    显然和时间有关系，同时和金额有关系
    剩下的如果有需要就接着列
    那么首先思考当前状态可以通过什么样的方式转移过来
    可以是前一天什么也不干，就是f[i][j]=max(f[i-1][j],f[i][j])
    剩下的就是通过买股票或者卖股票达到了当前的状态
    首先卖股票，那么肯定是i-w-1天及其之前转移过来的，因为什么也不干的时候就已经对i-w-1天之前的状态取了最优
    所以说直接从这一天进行转移即可，那么需要注意股票卖出的上限以及自己当前的股票数量
    同理是买股票，买股票分为两种，第一种是我之前什么股票也没有，就在当天买了这么多，并不依赖于之前的状态，直接赋值即可
    第二种是i-w-1天及其之前转移过来的，同卖股票一样，直接进行转移即可
    但是这么进行转移的时候，时间复杂度是O(n^3)的，遍历需要层循环，当前层遍历之前的层，又是两层循环

    如果对式子乘开来算的话，可以发现f[i][j]=max(f[i][j],f[i-w-1]-j*ap_i+k*ap_i)可以把j*ap_i提出来，j-as_i<=k<=j-1，就相当于每次都需要k所处窗口的最大值，可以通过滑动窗口进行维护

    用单调队列维护滑动窗口最大值的时候，维护买股票是需要正序枚举的
    而维护卖股票是需要逆序枚举的，因为是用到大于自己的先前的股票的状态，所以要逆向枚举

*/
void sol() {
    int t,maxp,w;
    cin>>t>>maxp>>w;

    vector<vector<int>> f(2010,vector<int>(2010,INT32_MIN));
    vector<int> q(2010,0);
    int ans=0;
    for(int i=1;i<=t;i++){
        int ap,bp,as,bs;
        cin>>ap>>bp>>as>>bs;
        for(int j=0;j<=as;j++){
            f[i][j]=-j*ap;
        }
        for(int j=0;j<=maxp;j++){
            f[i][j]=max(f[i][j],f[i-1][j]);
        }
        if(i<=w) continue;

        int l=1,r=0;
        for(int j=0;j<=maxp;j++){
            while(l<=r&&q[l]<j-as){
                l++;
            }
            while(l<=r&&f[i-w-1][q[r]]+q[r]*ap<=f[i-w-1][j]+j*ap){
                r--;
            }
            q[++r]=j;
            if(l<=r){
                f[i][j]=max(f[i][j],f[i-w-1][q[l]]+q[l]*ap-j*ap);
            }
        }
    
        l=1,r=0;
        for(int j=maxp;j>=0;j--){
            while(l<=r&&q[l]>j+bs){
                l++;
            }
            while(l<=r&&f[i-w-1][q[r]]+q[r]*bp<=f[i-w-1][j]+j*bp){
                r--;
            }
            q[++r]=j;
            if(l<=r){
                f[i][j]=max(f[i][j],f[i-1-w][q[l]]+q[l]*bp-j*bp);
            }
        }
    }
    for(int i=0;i<=maxp;i++){
        ans=max(ans,f[t][i]);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}