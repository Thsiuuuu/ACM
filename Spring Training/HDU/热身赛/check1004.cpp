#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    int cnt=0;
    for(int x=2;x<=165;x++){
        if(cnt==30) break;
        bool f=false;
        for(int i=2;i<x;i++){
            if(x%i==0){
                f=true;
                break;
            }
        }
        if(!f) {
            cout<<x<<",";
            cnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}