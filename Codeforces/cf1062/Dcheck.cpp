#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N=1e18;
const int M=1e5;
bool check(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return true;
        }
    }
    return false;
}



signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int i=0,cnt=0,j=0;
    int mul=1;
    while(++i){
        if(!check(i)){
            if(mul*i<=N){
                mul*=i;
            }else{
                cnt++;
                if(cnt==M+1) break;
                mul=i;
            }
            j++;
        }
    }
    cout<<i;
    return 0;

}