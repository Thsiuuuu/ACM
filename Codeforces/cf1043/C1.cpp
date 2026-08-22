#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*

    贪心
    能贪多少是多少，如果能贪不贪，会让底下的取，次数一定比当前次数大
    所以这种取法必然是最优解


*/
const int temp=pow(3,25);

void sol(){
    int n;
    cin>>n;
    int cur=temp;
    int ans=0;
    for(int i=25;i>=0;i--){
        while(cur<=n){
            n-=cur;
            ans+=(cur*3+(i)*cur/3);
        }
        cur/=3;
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