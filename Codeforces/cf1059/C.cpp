#include <bits/stdc++.h>
using namespace std;
#define int long long 

void  sol(){
    int a,b;
    cin>>a>>b;
    int l;
    for(int i=33;i>=0&&((a>>i)&1)==0;i--,l=i){
        if((b>>i)&1){
            cout<<"-1\n";
            return ;
        }
    }
    if(((a>>l)&1)&&((b>>l)&1)){
        cout<<"1\n";
        cout<<(a^b)<<'\n';
    }else{
        cout<<"2\n";
        cout<<(a^(1<<l)^b)<<" "<<(1<<l)<<'\n';
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