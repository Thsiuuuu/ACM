#include <bits/stdc++.h>
using namespace std;

/*

    %3一定有0,1,2三种情况
    0,15,30最特殊
    1,16,31
    2,17,32
    这个分布具有周期性，每15个一组

*/

void sol(){
    int n;
    cin>>n;
    cout<<(((n+1)/15)*3+min((n+1)%15,3))<<'\n';
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