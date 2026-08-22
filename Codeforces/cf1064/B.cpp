#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*

    被这道题阴了
    因为没有手玩样例
    手玩样例就可以发现，代价至少为1（因为要挪鼠标）
    先一直放在右端点a，如果每个窗口数量情况下都能到达右端点，代价就是1
    这里等价于a=b
    也有可能一直放在b，也就是对于每一个数量下，始终都是b最小，那就说明a/n>=b
    如果不是的话，b<a&&a/n<b，右端点最开始是a，然后变成了b，代价就是2

*/
void sol(){
    int a,b,n;
    cin>>a>>b>>n;
    if(a==b||(a/n>=b)){
        cout<<"1\n";
    }else{
        cout<<"2\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0    ;
}