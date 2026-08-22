#include <bits/stdc++.h>
using namespace std;
#define int long long 


void sol(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"1\n";
    }else if(n==2){
        cout<<"3\n";
    }else if(n==3){
        cout<<"2\n";
    }else{
        int sum=0;
        int st;
        for(int i=63;i>=0;i--){
            if((n>>i)&1){
                sum++;
                if(sum==1) st=i;
            }
        } 
        // cout<<st<<'\n';
        if(sum==1){
            cout<<n<<'\n';
        }else{
            cout<<(((1ll)<<(st+1))-1ll)<<'\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio();
    cin.tie(0),cout.tie(0);


    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}