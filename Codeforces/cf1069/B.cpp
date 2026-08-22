#include <bits/stdc++.h>
using namespace std;
/*

    区间异或和可以转化成前缀异或和

    要求[l,r]区间异或和是0，那么等价于pre_l-1=pre_r
    并且其他地方异或和都不一样，就意味着只要不是这两个，必有pre_l-1!=pre_r
    可以构造一个递增的序列，然后直接令pre_l-1=pre_r即可

*/

void sol(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> pre(n+1);
    iota(pre.begin(),pre.end(),0);
    pre[l-1]=pre[r];
    for(int i=1;i<=n;i++){
        cout<<(pre[i]^pre[i-1])<<" ";
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}