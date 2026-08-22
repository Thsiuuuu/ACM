#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<double> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    double sum=0;
    for(int i=0;i<n;i++){
        sum=(sum/2+a[i]);
        // cout<<sum<<'\n';
        if(sum<0){
            cout<<"-";
        }else if(sum>0){
            cout<<"+";
        }else{
            cout<<"0";
        }
    }
    return 0;
}