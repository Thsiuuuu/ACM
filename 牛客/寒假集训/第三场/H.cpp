#include <bits/stdc++.h>
using namespace std;
/*

    计算几何，见到三角形面积想叉积

*/
#define double long double
void sol() {
    double xa,xb,ya,yb;
    cin>>xa>>ya>>xb>>yb;
    if(yb==ya){
        if(llabs(yb)*llabs(xa-xb)==4){
            cout<<"0";
        }else{
            cout<<"no answer";
        }
    }else{
        cout<<fixed<<setprecision(12)<<(xa*yb-xb*ya-4)/(yb-ya);
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