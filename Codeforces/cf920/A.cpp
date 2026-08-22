#include <bits/stdc++.h>
using namespace std;
/*

    不一样横坐标之差绝对值就是边长
    平方一下就是面积
    即，横坐标最大值减去横坐标最小值

*/
void sol() {

    int ori;
    int x,y;
    cin>>x>>y;
    ori=x;
    bool flag=false;
    for(int i=1;i<=3;i++){
        cin>>x>>y;
        if(x!=ori&&flag==false){
            cout<<(x-ori)*(x-ori)<<'\n';
            flag=true;
        }
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