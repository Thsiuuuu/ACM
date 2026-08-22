#include <bits/stdc++.h>
using namespace std;
/*

    首先如果走奇数步，先手胜，反之后手胜
    那么总的操作次数就等于n-当前的石头堆数

    可以每次拿一个，这样操作次数最长，如果最长的操作次数我们必胜，那么对方不管怎么拿，我们都有办法进行操作
    如果我们必败，那么我们不管怎么做，对方都有相应的办法维持对方必胜

    所以说最长操作次数进行维护，最后一定是m,m,m,...n%m

*/
void sol() {
    int n,m;

    cin>>n>>m;
    if(((n-n/m+(n%m!=0))%2==1)){
        cout<<"0\n";
    }else{
        cout<<"1\n";
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