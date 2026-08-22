#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int sum[N];

int main(){

    for(int i=1;i<=3e3;i++){
        int cpy=i;
        int ans=0;
        while(cpy){
            ans+=cpy%10;
            cpy/=10;
        }
        cout<<i<<" "<<i-ans<<'\n';
    }
    return 0;
}