#include <bits/stdc++.h>
using namespace std;
#define int long long 

/*


    前缀和+哈希
    1.首先可以把a b转化为1 -1
    2.最后的和减去某一区间和为0
    3.可以枚举右端点，通过哈希表查找最近的左端点，并更新答案
    4.如果最后删掉的长度就是n，说明删掉整个
    5.特殊边界处理，如果

*/
void sol(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i-1]=='a'?1:(-1));
    int sum=pre[n];
    if(sum==0){
        cout<<"0\n";
        return ;
    }
    map<int,int> mp;
    mp[0]=0;
    int ans=1919810114514;
    for(int r=1;r<=n;r++){
        int need=pre[r]-sum;
        if(mp.find(need)!=mp.end()){
            ans=min(ans,r-mp[need]);
        }
        mp[pre[r]]=r;
    }
    cout<<((ans==n)?-1:ans)<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}