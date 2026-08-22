#include <bits/stdc++.h>
using namespace std;
/*

    忽略了是选择一个，不是任意的
    所以说Alice在选的时候，如果全都是a集合的倍数，那么一定是自己的
    对Bob也成立
    对于中间的数需要特殊判断一下

*/
#define int long long 
void sol() {
    int n,m;
    cin>>n>>m;
    vector<int> but(n+m+1,0),a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    for(int i=0;i<a.size();i++){
        for(int j=a[i];j<=n+m;j+=a[i]){
            but[j]++;
        }
    }
    n=a.size();
    int num1=0,num2=0,mid=0;
    for(int i=0;i<m;i++){
        cin>>b[i];
        if(but[b[i]]==n){
            num1++;
        }else if(!but[b[i]]){
            num2++;
        }else{
            mid++;
        }
    }
    num1+=((mid+1)/2);
    num2+=(mid-(mid+1)/2);
    if(num1<=num2){
        cout<<"Bob\n";
    }else{
        cout<<"Alice\n";
    }
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