#include <bits/stdc++.h>
using  namespace std;

void sol(){
    int n;
    cin>>n;
    if(n%3==0) cout<<"0\n";
    else{
        cout<<3-(n%3)<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}