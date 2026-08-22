#include <bits/stdc++.h>
using namespace std;
/*

    数据范围不大，n^2的算法
    哪种方法都想一想，枚举可不可以？
    依次枚举谁可以成为最大值，那么每个数字的上下限都是确定的，怎么找出一个位置最大满足的数是多少
    那么就是二分了
    从该位置开始，要向后看，a[i]<=a[i+1]+1必然成立
    总的时间复杂度是O(n^2logk)

*/

#define int long long

vector<int> a;
int n,k;

bool check(int id,int cur){
    int rem=k;

    for(int j=id,i=id+1;i<=n;i++,j++){
        if(rem<0){
            return false;
        }
        rem=rem-(cur-a[j]);
        // a[j]=cur;
        if(rem>=0&&cur<=a[i]+1){
            return true;
        }
        cur--;
    }
    return false;
}

void sol() {
    // int n,k;
    cin>>n>>k;
    a.resize(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }    
    int res=-1;
    for(int i=1;i<=n-1;i++){
        int l=a[i],r=a[i]+k;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(i,mid)){
                // cout<<l<<" "<<r<<" "<<mid<<'\n';
                res=max(res,mid);
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
    }
    res=max(res,*max_element(a.begin()+1,a.end()));
    cout<<res<<'\n';
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