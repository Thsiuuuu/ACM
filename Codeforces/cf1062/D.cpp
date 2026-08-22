#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long 

/*

    先想一想什么时候无解
    显然所有的因数的积超过1e18就无解了
    否则是有解的
    然后这个答案类似于求mex{因数}
    这个最多是不会超过53的

*/

const int N=1e18;
void sol(){

    int n;
    cin>>n;

    vector<int> st={2,3,5,7,11,13,17,19,23,29,31,37,39,41,43,47,51,53};
    int ans=1145141919810;    
    for(int i=0,x;i<n;i++){
        cin>>x;
        int mn=1145141919810;
        for(int pri:st){
            if(x%pri){
                mn=pri;
                break;
            }
        }
        ans=min(mn,ans);
    }   
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