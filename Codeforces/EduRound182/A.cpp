#include <bits/stdc++.h>
using namespace std;
/*

    错因：
    全部相同和全部不同不意味着一定存在mod=3

*/
void sol(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%3){
        cout<<"0 0\n";
        return ;
    } 
    cout<<"1 2\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}