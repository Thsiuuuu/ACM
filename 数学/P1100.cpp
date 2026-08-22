#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    int res1=0,res2=0;
    for(int i=31;i>=16;i--){
        res1<<=1;
        res1|=((n>>i)&1);
    }
    for(int i=15;i>=0;i--){
        res2<<=1;
        res2|=((n>>i)&1);
    }
    cout<<((res2<<16)|(res1));
    return 0;
}