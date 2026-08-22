#include <bits/stdc++.h>
using namespace std;
/*

    1.按位拆解
    2.手玩样例，发现合法的一定是偶数
    3.进一步手玩，发现一定是对称的


*/

#define int long long 
void sol(){

    int n;
    cin>>n;

    vector<int> cnt(32);
    cnt[0]=0;
    int tot=0;
    for(int i=0;i<=31;i++){
        if(n&(1<<i)){
            cnt[++tot]=i;
        }
    }
    if(tot&1){
        cout<<"NO\n";
    }else{
        int mid=cnt[tot/2]+cnt[tot/2+1];
        int l,r;
        if(mid&1){l=mid/2+1,r=mid/2;}
        else{l=mid/2+1,r=mid/2-1;}
        // if((30-l)<(r)){
        //     cout<<"NO\n";
        //     return ;
        // }

        /*
        
            hack样例:
                n=(1<<29)|(1<<27)

                不应该对生成n的数进行限制
        
        */
        while((l<=30)&&(r>=0)){
            if(((n>>l)&1)!=((n>>r)&1)){
                cout<<"NO\n";
                return ;
            }
            l++,r--;
        }
        cout<<"YES\n";
    }   
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