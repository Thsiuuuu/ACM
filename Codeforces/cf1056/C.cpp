#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int mod=676767677;

/*
    推公式
    一个人只能看见左边的左边，以及右边的右边
    然后需要考虑相邻项的关系
    就可以推出一个式子
    但是是充分不必要的
    所以需要逆向的检测
    可以拿前缀和进行检测
    总的时间复杂度O(n)
*/


int res(const vector<int>&a,vector<int>&f,int num,int n){
    
    f[1]=num;

    vector<vector<int>> pre(n+1,vector<int>(2,0));

    // cout<<num<<'\n';
    for(int i=2;i<=n;i++){
        int tmp=a[i]-a[i-1]-f[i-1]+1;
        if(tmp<0||tmp>1){
            return 0;
        }
        f[i]=tmp;
    }

    for(int i=1;i<=n;i++){
        pre[i][0]+=(pre[i-1][0]+(f[i]^1));
        pre[i][1]+=(pre[i-1][1]+(f[i]&1));
    
        // cout<<i<<" "<<pre[i][0]<<" "<<pre[i][1]<<'\n';
    
    }

    for(int i=1;i<=n;i++){
        if(a[i]!=((pre[i][1]-pre[0][1])+(pre[n][0]-pre[i-1][0]))){
            return 0;
        }
    }

    return 1;
}

void sol(){

    int n,ans=0;    
    cin>>n;

    vector<int> a(n+1,0),f(n+1,0);
    
    for(int i=1;i<=n;i++) cin>>a[i];
    
    for(int i=0;i<=1;i++){
        // if(res(a,f,i,n)){
        //     for(int j=1;j<=n;j++){
        //         cout<<f[j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        ans+=res(a,f,i,n);
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