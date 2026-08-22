#include <bits/stdc++.h>
using namespace std;
/*

    求合法连续区间数量，和前两场的计算几何很相似，都用到了双指针
    但是使用双指针需要保证，如果[l,r]合法，那么它们的任意一个子区间都是合法的

    首先一定有a+b=(a^b)+(a&b)，所以说a+b>=a^b，当且仅当a和b没有二进制位同时为1
    所以说如果一个[l,r]满足题意的话，那么在插入过程当中没有任何两个数有二进制位的重叠
    所以说都是直接在某一位上加1，拿走任意的前缀和后缀，剩下的仍然相等

    枚举右端点即可

*/

#define int long long 

void sol() {
    int n;
    cin>>n;
    vector<int> a(n+1),yihuo(n+1,0),sum(n+1,0);
    // map<int,int> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    int ans=0;
    int sum1=0,sum2=0;
    for(int l=1,r=1;r<=n;r++){
        sum1^=a[r];
        sum2+=a[r];
        while(l<=r&&sum1!=sum2){
            sum1^=a[l];
            sum2-=a[l];
            l++;
        }
        ans+=(r-l+1);
    }
    cout<<ans;
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