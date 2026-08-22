#include <bits/stdc++.h>
using namespace std;
/*

    暴力改超时
    给每一个点记录最近一次修改时间
    然后维护最近一次更新时间，一旦修改时间小于更新时间就说明应该更新
    然后维护更新时间就可以，最后需要把所有元素检查一次

*/
#define ll long long 
void sol() {
    int n,m,h;
    cin>>n>>m>>h;

    vector<ll> a(n+1,0);
    vector<array<ll,2>> cur(n+1,{0,0});
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cur[i][0]=a[i];
    }  
    int last=1;
    for(int i=1;i<=m;i++){
        int b,c;
        cin>>b>>c;
        if(cur[b][1]<last){
            cur[b][0]=a[b];
        }
        cur[b][1]=i;
        if(cur[b][0]+c>h){
            last=i;
            cur[b][0]=a[b];
        }else{
            cur[b][0]+=c;
        }
    }
    for(int i=1;i<=n;i++){
        if(cur[i][1]<last){
            cur[i][0]=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        cout<<cur[i][0]<<" ";
    }
    cout<<'\n';
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