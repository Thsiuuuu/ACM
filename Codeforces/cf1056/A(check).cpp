#include <bits/stdc++.h>
using namespace std;

void rd(int n){
    int sum1=n,sum2=0;

    int res1=0,res2=0;
    while(sum1!=1||sum2!=1){

        res2+=(sum2/2);
        sum2-=(sum2/2);

        res1+=(sum1/2);
        sum2+=(sum1/2);
        sum1-=(sum1/2);
    }
    cout<<res1+res2+1<<'\n';
    // cout<<"number "<<n<<" "<<res1+res2+1<<'\n';
}

int  main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        rd(n);
    }
    return 0;
}