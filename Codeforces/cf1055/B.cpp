#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*


    这个不妨可以先从共线的角度上想，因为后者始终可以保持和前者共线，所以说前者能走的最多步数就是后者朝着它的这个方向能走的x y方向的最长的距离
    如果不共线的话，需要两个方向上的距离都变成0，然后后面的人可以斜着走，这个时候还是由最长的那一条所决定的，因为短的那个方向不管怎么走，最后都能在长的之前变成同一个方向
    所以说枚举出横竖两个方向上的最长边即可
    cf官方给的代码比较简洁（）

*/

void sol(){

    int n,ra,rb,rc,rd;
    cin>>n>>ra>>rb>>rc>>rd;
    int ans=0;
    if(rc>ra){
        ans=max(ans,rc);
    }else if(rc<ra){
        ans=max(ans,n-rc);
    }
    if(rd>rb){
        ans=max(ans,rd);
    }else if(rd<rb){
        ans=max(ans,n-rd);
    }
    cout<<ans<<'\n';
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