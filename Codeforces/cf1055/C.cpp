#include <bits/stdc++.h>
using namespace std;

const int N=3e5+10;
int sum[2][N];
int diff[N],difsum[N];
int a[N];

/*


    很容易观察到相邻两项去消一个别的一定是代价为1的，这时候是最小
    问题是之后怎么做，如果消掉一个两边一样中间不一样的，一定又构造出一个相邻两项
    也就是说，只要存在一个相邻两项一样，并且还存在1的话，那这个单独的一定会被消掉（用理论解释的话，就是聂天一说的抽屉原理了awa），
    最终变成每段数量至少大于等于2的完全连续的区间，然后这个时候还是可以花费代价为1去进行消除的

    然后就是如果是完全交错的，就是花费2的代价，构造出一个相邻的2的长度的序列，进行消除即可

    然后分别用前缀和维护一下0,1以及相邻两项不同的个数即可
    本题的难点在于观察到代价为1的最优解之后，怎么能够继续构造最优解

*/

void sol(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        sum[0][i]=sum[0][i-1];
        sum[1][i]=sum[1][i-1];
        sum[a[i]][i]++;//预处理前缀和，是哪个就加那个

        diff[i]=(a[i]!=a[i-1]);
        difsum[i]=difsum[i-1]+diff[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int s0=sum[0][r]-sum[0][l-1],s1=sum[1][r]-sum[1][l-1];
        if(s0%3||s1%3){
            cout<<"-1\n";
            continue;
        }
        if(difsum[r]-difsum[l]==r-l)    cout<<(r-l-2)/3+2<<'\n';
        else cout<<(r-l+1)/3<<'\n';
    }
    return ;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}