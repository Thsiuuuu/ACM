#include <bits/stdc++.h>
using namespace std;
/*

    错因：二进制位理解错了
    没统计个数检验导致的
*/

void sol(){
    int n;
    cin>>n;
    cout<<(1<<n)-1<<" ";
    for(int i=n-1;i>=0;i--){
        int sum=((1<<i)-1);
        while(sum<((1<<n)-1)){
            cout<<sum<<" ";
            sum+=(1<<(i+1));
        }
    }
    cout<<'\n';
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