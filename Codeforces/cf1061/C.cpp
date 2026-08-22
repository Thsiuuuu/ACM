#include <bits/stdc++.h>
using namespace std;
/*

    如果直接根据题意去想答案比较困难的话，尝试枚举
    因为数据量不大，直接枚举时间复杂度是O(n^2)
    然后去想一下这个怎么算，对于一个g，能拆出因数的话，必然是>4*g或等于3*g，否则不如直接删除
    因为>4*g，可以构造出合法的两个因数，介于(3*g,4*g)之间的数就不能构造了，因为g _ 2g || g _ g都不行
    所以对于剩下情况的数，如果不是倍数的话，就只能直接删除
    快速查询一个区间之内的数字可以采用前缀和

    然后就是代码实现，直接取最小值比较困难的话，可以多枚举几层

*/

void sol(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int> cnt(a[n-1]+1,0),pre(a[n-1]+1,0);
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
    }
    for(int i=1;i<=a[n-1];i++){
        pre[i]=pre[i-1]+cnt[i];
    }
    for(int g=a[n-1];g>=1;g--){
        int sum=0;
        if(g<=a[n-1]) sum+=cnt[g];
        if(2*g<=a[n-1]) sum+=cnt[2*g];
        if(3*g<=a[n-1]) sum+=cnt[3*g];
        if(4*g<=a[n-1]) sum+=(pre[a[n-1]]-pre[4*g-1]);
        sum=n-sum;
        if(sum>k) continue;
        else{
            cout<<g<<'\n';
            return ;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}