#include <bits/stdc++.h>
using namespace std;
/*

    能走尽走
    因为当前的位置至多对下一条查询有影响
    也就是说，当前的位置不走至少会浪费一条，未来还有可能浪费
    但是当前的位置走了，只会浪费一条
    所以当前的位置一定是最优的

    审错题意了
    原题意思更简单
    只需分类讨论
    相邻任务时间差为1，若都在原地，则不加分，反之加一分
    大于1，原地是差值/2*2,否则先跑一个,差值/2*2

    注意开头和结尾的特殊情况，因为任务要求搞完了只要时间够是还可以接着跑的

*/

#define int long long 

struct node{
    int a,b;
};
void sol(){ 

    int n,m;
    cin>>n>>m;
    vector<node> vec;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(i==0&&a){
            vec.push_back({0,0});
        }
        vec.push_back({a,b});
    }
    int ans=0;
    int tim=0;
    for(int i=0;i<vec.size()-1;i++){
        
        int sum=vec[i+1].a-vec[i].a;
        if(vec[i+1].b==vec[i].b){
            ans+=(sum/2)*2;
        }else{
            ans++;
            sum--;                
            ans+=(sum/2)*2;
        }
        tim=vec[i+1].a;
    }
    if(tim<m) ans+=(m-tim);
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
