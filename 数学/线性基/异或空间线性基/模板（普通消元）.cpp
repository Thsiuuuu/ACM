#include <iostream>
#include <algorithm>
using ull=unsigned long long ;//using 定义类型别名

ull p[64];

void insert(ull x){
    for(int i=63;~i;i--){
        if(!(x>>i)) continue;
        if(!p[i]){
            p[i]=x;
            break;
        }
        x^=p[i];//第i位没有基，就直接当作基，有基就消掉
    }
}

using std::cin;
using std::cout;//从std命名空间中引入cin成员，后面直接写cin就不用写std::cin

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    ull a;
    for(int i=1;i<=n;i++){
        cin>>a;
        insert(a);
    }
    ull ans=0;
    for(int i=63;~i;i--){
        ans=std::max(ans,ans^p[i]);
    }
    cout<<ans<<'\n';
    return 0;
}