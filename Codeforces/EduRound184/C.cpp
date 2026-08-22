#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*

    推公式题，已经很多次折在这种题上了
    如果一个题不会做，看看答案能不能写出来表达式
    表达式可不可以进行转换
    自己没有做到上面的东西
    写出来表达式之后，可以发现就是对每一个位置，维护前缀的一个函数值，然后进行计算即可
*/
void sol() {
    int n;
    cin>>n;
    vector<int> a(n+1),pre(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    int mn=1145141919;
    int tot=pre[n];
    int ans=tot;
    for(int r=1;r<=n;r++){
        int cur=r*r+r-pre[r];
        if(mn>(r*r-r-pre[r-1])){
            mn=r*r-r-pre[r-1];
        }
        ans=max(ans,tot+cur-mn);
    }
    cout<<ans<<'\n';
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