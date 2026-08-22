#include <bits/stdc++.h>
using namespace std;
/*

    手玩样例，发现可以枚举奶牛的数量

    读错题了（）奇数个一定不行
    偶数个，可以用4进行划分，0,1 2 3...n/4
*/
void sol() {
    int n;
    cin>>n;
    if(n&1){
        cout<<"0\n";
        return ;
    }
    cout<<(n/4+1)<<'\n';
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