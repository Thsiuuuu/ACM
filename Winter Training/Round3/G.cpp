#include <bits/stdc++.h>
using namespace std;
/*

    昏厥了（悲）
    首先一种颜色就是所有颜色加在一起
    不难证明出，任何一个度大于一的节点都会位于至少两个颜色联通块的交界处
    对于两种颜色，显然能够对答案产生贡献的一定是当前度大于1的节点，会多加一次它的点权，并且对其他联通块的贡献没有影响
    每次都会增加一个点的贡献，所以说只要在当前能产生度数的点中选取点权最大的点就可以

*/
#define int long long

struct node{
    int number,val;
    bool operator<(const node&other)const{
        if(val==other.val) return number<other.number;
        return val>other.val;
    }
};


void sol() {
    int n;
    cin>>n;
    vector<node> w(n+1);
    for(int i=1;i<=n;i++){
        cin>>w[i].val;
        w[i].number=i;
    }
    vector<int> deg(n+1,0);
    sort(w.begin()+1,w.end());
    int sum=0;
    for(int i=0,u,v;i<n-1;i++){
        cin>>u>>v;
        deg[u]++,deg[v]++;
    }
    for(int i=1;i<=n;i++){
        sum+=w[i].val;
    }
    
    for(int i=1;i<=n;){
        cout<<sum<<" ";
        while(i<=n&&deg[w[i].number]==1){
            i++;
        }
        if(i<=n&&deg[w[i].number]>1){
            sum+=w[i].val;
            deg[w[i].number]--;
        }
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}