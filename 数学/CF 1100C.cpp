#include <bits/stdc++.h>
using namespace std;
/*

    如果不是2的幂次-1
    那么很容易让b为a在当前位数下的取反，可以保证异或值最大，并且gcd等于其自身，其余的一定小于它
    如果是2的幂次，这个问题等于gcd(a-b,b)=gcd(a,b)相当于求a和b<a的最大公因数，那么a的最大的因数一定是答案，因为其它的都小于它并且令b=最大因数就可以

*/
void sol() {
    int a;
    cin>>a;
    int k;
    for(int i=27;i>=0;i--){
        if(a>>i&1){
            k=i;
            break;
        }
    }
    if(__builtin_popcount(a)==k+1){
        int number=1;
        for(int i=2;i*i<=a;i++){
            if(a%i==0){
                number=a/i;
                break;
            }
        }
        cout<<number<<'\n';
    }else{
        cout<<(1<<(k+1))-1<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}