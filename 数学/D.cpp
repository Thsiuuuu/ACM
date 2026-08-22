#include <bits/stdc++.h>
using namespace std;
#define int long long 
// #define double long double
/*

    题目链接
    https://www.luogu.com.cn/problem/U597692

*/
int power_lsd(int a,int b,int p){
    int res=1;
    while(b){
        if(b&1){
            res=(1ll*res*a)%p;
        }
        b>>=1;
        a=(1ll*a*a)%p;
    }
    return res;
}

int power_msd(int a,int b,int digits){
    long double exp=(long double)b*log10l((long double)a);
    exp-=floor(exp);
    long double res=pow(10.0l,exp+digits-1);
    return (int)(res+1e-9l);
}

void sol(int i){
    int n,k;
    cin>>n>>k;
    cout<<"Case "<<i<<": ";
    cout<<power_msd(n,k,3)<<" ";
    cout<<setw(3)<<setfill('0')<<power_lsd(n,k,1000)<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}