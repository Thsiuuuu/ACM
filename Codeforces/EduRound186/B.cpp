#include <bits/stdc++.h>
using namespace std;
/*



*/
int res(int a,int b){
    int level=1;
    int cur=1;
    while(1){
        if(cur&1){
            if(a<level){
                return (cur-1);
            }
            a-=level;
        }else{
            if(b<level){
                return (cur-1);
            }
            b-=level;
        }
        cur++;
        level<<=1;
    }
}


void sol() {
    int a,b;
    cin>>a>>b;
    cout<<max(res(a,b),res(b,a))<<'\n';
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