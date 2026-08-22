#include <bits/stdc++.h>
using namespace std;
/*

    还是等差数列差分，为了方便处理边界问题就把范围右移了

*/

#define int long long 
const int del=3e4;
vector<int> diff(2000000,0);

void change(int l,int r,int s,int e,int d){
    diff[l+del]+=s;
    diff[l+1+del]+=d-s;
    diff[r+1+del]-=d+e;
    diff[r+2+del]+=e;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    while(n--){
        int v,x;
        cin>>v>>x;
        change(x-3*v,x-2*v-1,0,v-1,1);
        change(x-2*v,x,v,-v,-1);
        change(x+1,x+2*v-1,-v+1,v-1,1);
        change(x+2*v,x+3*v,v,0,-1);
    }
    for(int i=1;i<=m+del;i++) diff[i]+=diff[i-1];
    for(int i=1;i<=m+del;i++) diff[i]+=diff[i-1];
    for(int i=1;i<=m;i++) cout<<diff[i+del]<<" ";
    return 0;
}