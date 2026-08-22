#include <bits/stdc++.h>
using namespace std;
/*

    不妨以x为根，那么所有节点数量为1的时候，必胜，只有一个子树的时候，必胜
    对于剩下的情况，最后的情况一定是x只和一个节点相连，那么在这之前的上一个状态有两种可能，一个是拿走了x的邻接节点，另外一个是拿走这个子树的节点
    但显然拿走子树节点一定是不可能的，因为这个时候有必胜解为什么要拿这个必败解呢（因为每个人要选最优解）
    所以上一个状态一定是x有两个子节点
    也就是说谁面临这一状态谁就输了
    每轮都拿走一个节点，谁面临上述状态，谁就输了

*/
void dfs(int u,int fa,const vector<vector<int>>& e,vector<int>& siz){
    for(int v:e[u]){
        if(v^fa){
            dfs(v,u,e,siz);
            siz[u]+=siz[v];
        }
    }
}

void sol(){
    int n,x;
    cin>>n>>x;
    vector<int> deg(n+1,0),siz(n+1,1);
    vector<vector<int>> e(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        
        e[u].push_back(v);
        e[v].push_back(u);
    }
    // dfs(x,0,e,siz);
    if(n==1){
        cout<<"Ayush\n";
        return ;
    }//没有特判！
    if(e[x].size()==1){
        // if(siz[e[x][0]]&1){
        //     cout<<"Ashish\n";
        // }else 
        cout<<"Ayush\n";
    }else{
        if(n&1) cout<<"Ashish\n";
        else cout<<"Ayush\n";
        // int cnt=0;
        // for(int v:e[x]){
        //     if(siz[v]&1){
        //         cnt++;
        //     }
        // }
        // if(cnt&1){
        //     cout<<"Ayush\n";
        // }else cout<<"Ashish\n";
    }
    
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