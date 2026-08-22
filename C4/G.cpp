#include <iostream>
#include <algorithm>


using namespace std;

#define int long long 


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
        }
        if(n%2==0){
            cout<<"Bob\n";
        }else cout<<"Alice\n";
    }
}