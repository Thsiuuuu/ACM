#include <iostream>
#include <algorithm>

using namespace std;


typedef long long ll;


const ll mx=2e18;

int main(){


    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;

    for(ll i=0;pow(2,i)<mx;i++){
        if(n>=pow(2,i)&&n<pow(2,i+1)){
               cout<<i+1;
         }
    }

    return 0;

}