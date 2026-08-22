#include <bits/stdc++.h>
using namespace std;
#define int long long  
/*

    首先考虑4和8的作用
    8是扩大一圈，4会额外多出来一块
    其次发现4和8的操作顺序对结果形状没有影响
    并且该图形是一个对称图形
    所以就可以判断一个点是不是在已知的图形内部了


*/

void sol(){
    int n,x,y;
    cin>>n>>x>>y;
    y=llabs(y),x=llabs(x);
    string s;
    cin>>s;
    int k=0;
    for(int i=0;i<n;i++){
        if(s[i]=='4') k++;
    }
    if((x+y<2*n-k+1)&&x<=n&&y<=n){
        cout<<"yes\n";
    }else{
        cout<<"no\n";
    }
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