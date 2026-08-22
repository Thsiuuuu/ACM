#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;
int que[N];
/*

    重点：
    1.dp的时候，想一想哪些地方对这个地方可能产生贡献，然后先列出暴力的式子，枚举断点是其中一种方法
    2.求区间和的时候，一定要想一想和前缀和有没有关系，可不可以利用前缀和进行转化

    这道题因为懒得特判了，所以说整体的向右平移了一格


*/
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> e(n+2),dp(n+2),pre(n+2,0);
    for(int i=2;i<=n+1;i++) cin>>e[i];
    for(int i=2;i<=n+1;i++) pre[i]=e[i]+pre[i-1];
    dp[0]=0;
    dp[1]=0;
    int head=0,tail=-1;
    que[++tail]=0;
    que[++tail]=1;
    for(int i=2;i<=n+1;i++){
        while(head<=tail&&que[head]<i-k-1) head++;
        dp[i]=pre[i]+dp[que[head]]-pre[que[head]+1];
        while(i+1<n+1&&head<=tail&&(dp[que[tail]]-pre[que[tail]+1])<=dp[i]-pre[i+1]) tail--;
        que[++tail]=i;//没写push操作
    }
    int ans=-1ll;
    for(int i=2;i<=n+1;i++) ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}