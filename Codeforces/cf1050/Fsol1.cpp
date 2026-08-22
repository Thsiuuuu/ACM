#include <bits/stdc++.h>
using namespace std;
/*

    代码实现题
    相当于每次总是条件允许情况下的最小值
    但是不一定每个位置一定有元素
    所以说要排序进行判断，每次找到当前位置最小，然后向后输出
    主要是代码不好写
    这里要按照长度进行排序，然后开一个指针遍历每一个长度，把合法长度放进去
    然后依次进行比较，如果不是最小的就去掉，如果已经走到结尾了，就走下一个位置。
    总的时间复杂度O(NlogN+S+Nsqrt(S))

    也可以进行暴力排序，因为时间复杂度分析发现，时间复杂度最大的情况就是阶梯形状
    这种情况下的l,n<=sqrt(N)


*/
void sol(){
    int n,k;
    cin>>n;
    vector<vector<int>> a(n);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a[i].assign(k,0);
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }
    }
    vector<int> b(n);
    iota(b.begin(),b.end(),0);
    sort(b.begin(),b.end(),[&](auto x,auto y){
        return a[x].size()<a[y].size();
    });
    int bi=0;
    int w=0;
    while(true){
        while(bi<n&&a[b[bi]].size()<=w) bi++;
        if(bi>=n) break;
        vector<int> c;
        for(int i=bi;i<n;i++) c.push_back(b[i]);
        while(true){
            vector<int> nc;
            int t=INT32_MAX;
            for(int x:c){
                if(a[x][w]<t){
                    nc.clear();
                    nc.push_back(x);
                    t=a[x][w];
                }else if(t==a[x][w]){
                    nc.push_back(x);
                }
            }
            // if(nc.empty()) break;
            cout<<a[nc[0]][w]<<" ";
            w++;
            if(w==a[nc[0]].size()) break;
            c=nc;
        }
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}