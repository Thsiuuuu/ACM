#include <bits/stdc++.h>
using namespace std;
#define int long long 
void sol(){

    int n;
    cin>>n;
    
    // string s=" ";
    
    if(n<128){
        cout<<n<<'\n';
        return ;
    }


    int cnt=0,num=0;
    bool fl=true;
    vector<int> ans;



    while(n){

        if(cnt==7){
            cnt=0;
            if(!fl){
                num=(num+(1<<7));
                
            }else{
                fl=false;
            } 
            ans.push_back(num);
            num=0;
        }

        num=num+((n&1)<<cnt);
        n>>=1;
        cnt++;
    }
    
    if(cnt&&(!fl)){
        ans.push_back((1<<7)+num);
    }
    

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    sol();
    return 0;
}