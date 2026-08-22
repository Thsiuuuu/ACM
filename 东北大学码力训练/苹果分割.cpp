#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define int long long 

int mndis=INT_MAX,dis,n,tosum=0;
vector<int> number;

void dfs(int cnt,int sum){

    if(cnt==n){
        int sum2=tosum-sum;
        dis=abs(sum-sum2);
        mndis=min(mndis,dis);
        return ;
    }
    dfs(cnt+1,sum+number[cnt]);
    dfs(cnt+1,sum);
}

signed main(){

    cin>>n;
    number.resize(n);
    for(int i=0;i<n;i++){cin>>number[i];tosum+=number[i];}
    dfs(0,0);
    cout<<mndis;
    return 0;
    
}