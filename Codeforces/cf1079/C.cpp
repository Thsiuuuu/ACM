#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ull unsigned long long 
void sol() {
    ull p,q;
    cin>>p>>q;
    if(3*p==2*q){
        cout<<"Bob\n";
    }else if(3*p<2*q){
        cout<<"Alice\n";
    }else if(p>=q){
        cout<<"Alice\n";
    }else{
        cout<<"Bob\n";
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