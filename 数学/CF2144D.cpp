#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
    首先观测到数据范围并不是很大，因为如果大于最大值结果都是一样的
    然后如果直接枚举，时间复杂度是O(n*x)的
    O(n*x)->log级别
    然后可以考虑如果外层优化不了，里层可不可以优化
    题干要求的是变化之后的总和减去没法抵消的花费
    因为这个变化有一部分的值变化之后是相同的
    这个核心在于找出变化之后每个值都有多少个数
    还是可以从昨天的双向关系找，一个单向关系找出来了，反向有什么信息
    整除后负责的值域一定是[(k-1)*x,k*x]的
    如果能够快速查找出这个区间内部有多少的数，一次x的时间复杂度是O(max(a_i)/x)
    总的时间复杂度是O(max(a_i)*(log(max(a_i))))
*/

#define int long long  
const int N=1e6+10;
int pre[N];
int t,n,y;
void sol(){
    cin>>n>>y;
    vector<int> c(N/2,0);
    int mx=-1145141919;
    for(int i=1;i<=n;i++){int x;cin>>x;mx=max(mx,x),c[x]++;}
    for(int i=1;i<=N/2-1;i++) pre[i]=(pre[i-1]+c[i]);
    int ans=-1e18;
    for(int x=2;x<=mx+1;x++){//取+1是因为加不加1没什么区别，但是当且仅当最大值为1的时候取不到最大值，因为x的最小值也是2，所以说上限应该去最大值+1
        int res=0;
        for(int i=1;i<=(mx)/x+1;i++){
            // cout<<pre[(i-1)*x+1]<<" "<<pre[i*x]<<'\n';
            res=res+i*(pre[min(i*x,N/3-1)]-pre[min((i-1)*x,N/3-1)])-y*max((int)0,(pre[min(i*x,N/3-1)]-pre[min((i-1)*x,N/3-1)])-c[i]);//还是注意不要越界，因为题目的数据范围有可能到达O(mx+x)<=O(2*mx)=4e5，或者数组开大一点
        }
        ans=max(res,ans);
    }
    for(int i=1;i<=N/2-1;i++){pre[i]=0;}
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}