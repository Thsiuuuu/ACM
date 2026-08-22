#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*


    昨天这个b的实现卡了很久，因为考虑到首0和尾0
    这里可以把它翻两倍，因为翻两倍能够把首0和尾0放到一起，并且不影响除了这两个以外每个答案的贡献

*/

void sol(){
    int n;
    string s;
    cin>>n>>s;
    s+=s;
    n*=2;
    int cur=0;
    int res=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            cur=0;
        }else{
            cur++;
        }
        res=max(res,cur);
    }
    cout<<res<<'\n';
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
