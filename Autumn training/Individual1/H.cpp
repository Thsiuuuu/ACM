#include <bits/stdc++.h>
using namespace std;
#define int long long  

/*

    首先明确有几种方法可以选糖
    1.选偶数糖，因为偶数糖总是伴随奇数糖出现的，可以把这两个糖捆绑到一起，代价x_i+y_i,贡献2
    2.选奇数糖，就是只选它，代价x_i,贡献1

    所以可以看做是选若干偶数糖和若干奇数糖
    对偶数糖，有便宜的糖一定是选最便宜的
    对奇数糖，一定是先选最便宜的糖
    因此枚举即可
*/

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> x(n+1),y(n+1);
    int val=1145141919810,ans=0,sum=0;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        val=min(val,x[i]+y[i]);
    }
    sort(x.begin()+1,x.end());
    for(int i=0;i<=n;i++){
        sum+=x[i];
        if(sum>m) break;
        ans=max(ans,(m-sum)/val*2+i);
    }
    cout<<ans;
    return 0;
}