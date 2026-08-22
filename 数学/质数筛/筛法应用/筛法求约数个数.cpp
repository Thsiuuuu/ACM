#include <bits/stdc++.h>
using namespace std;

const int N=1000010;

int p[N],vis[N],cnt;
int a[N];//记录i的最小质因子的个数
int d[N];//记录i的约数个数

void get(int n){
    d[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            p[++cnt]=i;
            a[i]=1;
            d[i]=2;
        }
        for(int j=1;i*p[j]<=n;j++){
            int m=i*p[j];
            vis[m]=1;
            if(i%p[j]==0){
                a[m]=a[i]+1;
                d[m]=d[i]/a[m]*(a[m]+1);
                break;
            }else{
                a[m]=1;
                d[m]=d[i]*2;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int  n;
    cin>>n;
    get(n);
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<d[i]<<'\n';
    }
    return 0;
}