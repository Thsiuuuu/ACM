#include <bits/stdc++.h>
using namespace std;

#define int  long long 

int a[7];
void sol(){

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    for(int i=1;i<=6;i++) cin>>a[i];
    int sum=0;
    for(int i=1;i<=2;i++){
        for(int j=3;j<=4;j++){
            for(int k=5;k<=6;k++){
                sum+=(a[i]*a[j]*a[k]);
            }
        }
    }
    cout<<sum<<'\n';
    return 0;
}