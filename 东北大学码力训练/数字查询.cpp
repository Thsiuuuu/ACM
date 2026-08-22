#include <iostream>
#include <string>
using namespace std;

#define int long long

int solve(int k){
    int d=1;
    while(true){
        int pwer=1;
        for(int i=0;i<d-1;i++) pwer*=10;
        int cur=d*9*pwer;
        if(k<=cur){
            int start=pwer;
            int num=start+(k-1)/d;
            int pos=(k-1)%d;
            string s=to_string(num);
            return s[pos]-'0';
        }
        k-=cur;
        d++;
    }
}


signed main(){
    int q;
    cin>>q;
    while(q--){
        int k;cin>>k;
        cout<<solve(k)<<"\n";
    }
    return 0;
}