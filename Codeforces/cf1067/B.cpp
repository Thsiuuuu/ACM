#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*

    非常奇怪的一道题
    一个数出现的次数分成奇偶来看
    偶数：/2是相等的奇数，那就直接放进去，如果是偶数，尝试可不可以变成差为2的两个奇数
    奇数：必然是一奇一偶
    如果能分成差为2的两个奇数的数的数量是偶数的话，那么它们可以内部消化
    如果不能的话，需要用奇数去补上，如果没有办法补上，就需要舍弃1个，然后填平。

*/


void sol(){
    int n;
    cin>>n;
    vector<int> vec(2*n+1,0);
    map<int,int> mp;
    for(int i=1;i<=2*n;i++){
        cin>>vec[i];
        mp[vec[i]]++;
    }
    int ans=0;
    int sum1=0,sum2=0;
    for(const auto&[key,val]:mp){
        if(val&1){
            sum2++;
        }else{
            int del=val/2;
            if(del&1){
                ans+=2;
            }else{
                sum1++;
            }
        }
    }
    if(sum1&1){
        ans=ans+sum2+sum1*2;
        if(!sum2){
            ans-=2;
        }
    }else{
        ans=ans+sum2+sum1*2;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}