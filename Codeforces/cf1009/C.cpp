#include <bits/stdc++.h>
using namespace std;

#define int long long  
/*

    非常糖的一个题
    可以用解不等式做，给出一个分析的方法
    手玩样例发现1000000和1111111这种一定不可以
    对于x+y>x^y这个不等式而言，必然是要有公共1才能消掉的
    对于y+x^y>x这个不等式而言，在x->x^y过程中对x有影响的
    只有x有y有，和x没有y有的，被异或消除的部分会在+y补回来
    所以为了让它大于x，还需要加上x没有y有的，也就是说至少要有一个0

*/
void sol(){
    int x;
    cin>>x;
    int cnt=0,len=0;
    for(int i=0;i<=33;i++){
        if((1ll<<i)&x){
            cnt++;
            len=i+1;
        }
    }
    if(cnt==1ll||cnt==len){
        cout<<"-1\n";
    }else cout<<((1ll<<(len-1))-1)<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}
