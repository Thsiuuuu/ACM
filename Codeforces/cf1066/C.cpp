#include <bits/stdc++.h>
using namespace std;
#define int long long  

/*

    对每个位置分成4种情况看：
    1，没有任何一种区间覆盖，那么直接填0
    2,只有最小值区间覆盖，那么直接填最小值
    3，只有mex区间覆盖，那么按次序从小到大填
    4，都是，那么就填k+1


*/

struct node{
    int c,l,r;
};
void sol(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<node> vec(q);
    vector<vector<int>> sgn(3,vector<int>(n+2,0));
    vector<int> ans(n+1,0);
    for(int i=0;i<q;i++){
        cin>>vec[i].c>>vec[i].l>>vec[i].r;
        sgn[vec[i].c][vec[i].l]++;
        sgn[vec[i].c][vec[i].r+1]--;
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            sgn[i][j]+=sgn[i][j-1];
        }
    }
    int cur=0;
    for(int i=1;i<=n;i++){
        int f1=sgn[1][i],f2=sgn[2][i];
        if(f1&&f2){
            ans[i]=k+1;
        }else if(f1){
            ans[i]=k;
        }else if(f2){
            ans[i]=cur++;
            cur%=k;
        }else{
            ans[i]=0;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<'\n';
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