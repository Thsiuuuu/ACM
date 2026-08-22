#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
// #define int long long 
#define double long double
void sol() {
    int n;
    cin>>n;
    bool f=true;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int curx,cury;
        curx=x,cury=i;
        while(curx%2==0){
            curx/=2;
        }
        while(cury%2==0){
            cury/=2;
        }
        if(curx!=cury){
            f=false;
        }
    }
    cout<<((!f)?"NO":"YES")<<'\n';
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