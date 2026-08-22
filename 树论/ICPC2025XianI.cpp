#include <bits/stdc++.h>
using namespace std;

/*

    不妨以1为根，那么x,y,1的三个点的异或路径的异或和总是位于中间的点的值，由此我们可以得到每个点的所有的祖先
    对于每个点的所有的祖先，需要找到该点的祖先数量恰好是这个点的祖先数量-1

    这里需要特判1只有一个子节点情况，那么哪个节点祖先是0，哪个节点就是与1邻接的
    记于2025.12.9 16:11:45
    瞻顾遗迹，如在昨日，令人长号不自禁
*/

#define int long long 
const int N=2010;
int yor[N][N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<set<int>> fa(n+1);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cin>>yor[i][j];
            yor[j][i]=yor[i][j];
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int sum=(yor[1][i]^yor[1][j]^yor[i][j]);
            if(sum^i) fa[i].insert(sum);
            if(sum^j) fa[j].insert(sum);
        }
    }

    // for(int i=1;i<=n;i++){
    //     cout<<i<<" ";
    //     for(int j:fa[i]) cout<<j<<" ";
    //     cout<<'\n';
    // }
    for(int i=2;i<=n;i++){
        if(fa[i].size()==0){
            cout<<i<<" 1\n";
            continue;
        }
        for(int j:fa[i]){
            if(fa[j].size()==fa[i].size()-1){
                cout<<i<<" "<<j<<'\n';
            }
        }
    }
    return 0;

}