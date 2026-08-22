#include <iostream>
#include <algorithm>


using namespace std;
#define int long long 

/*

    树

*/


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int num=n*(n-1)/2;
        if(k>=n-1){
            cout<<1<<"\n";
        }else{
            cout<<n<<"\n";
        }
    }
    return 0;
}