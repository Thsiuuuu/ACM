#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long 

void sol(){
    ll n;
    cin>>n;
    ll res=0;
    for(int k=1;k<31;k++){
        ll sum=0;
        for(int j=1;j<=n;j++){
            if(n-sum>=pow(j,k)){
                sum+=pow(j,k);
            }else break;
            // if(sum+pow(j,k)<=n){
            // }
            // else{
            //     break;
            // }
        }
        if(sum==n) res=k;
    }
    if(res){
        ll sum=0;
        for(int i=1;i<=n;i++){
            if(n-sum>=pow(i,res)){
                if(i>1) cout<<"+";
                sum+=pow(i,res);
                cout<<i<<"^"<<res;
            }else break;
        }
        cout<<'\n';
    }else cout<<"Impossible for "<<n<<".\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}