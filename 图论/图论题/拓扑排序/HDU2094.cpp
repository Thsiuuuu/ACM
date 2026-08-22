#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

/*

    种类并查集模板题
    二分图也可以做
    上面的结论是错的，因为没看清楚冠军是什么
    首先这个可以定义为一种偏序关系，然后根据这种关系建立单向图
    容易发现，如果这个图上有环的话，也就是说互相win了，肯定不能得出冠军
    判环可以通过拓扑排序，但是问题就是
    如果第一轮有多个入度为0的点，那么一定是不符合题意的
    因为多个入度为0的点没法说明谁一定是冠军了

    貌似题目里的冠军的定义是，没有输过的人就算冠军
    所以说不用完整的拓扑排序也可以
*/
const int N=1010;
vector<int> e[N];
int deg[N];

void init(int n){
    for(int i=1;i<=n;i++){
        e[i].clear();
        deg[i]=0;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    while(cin>>n){
        if(!n) return 0;
        map<string,int> mp;
        int j=0;
        for(int i=0;i<n;i++){
            string u,v;
            cin>>u>>v;
            if(!mp[u]) mp[u]=++j;
            if(!mp[v]) mp[v]=++j;
            int a=mp[u],b=mp[v];
            // cout<<a<<" "<<b<<'\n';
            e[a].push_back(b);  
            deg[b]++;
        }
        queue<int> que;
        int cnt=0;
        for(int i=1;i<=j;i++){
            if(!deg[i]){
                cnt++;
                // if(cnt>=2){
                //     break;
                // }
                que.push(i);
            }
        }
        if(cnt>=2||cnt==0){
            cout<<"No\n";
            // init(j);
            // continue;
        }else if(cnt==1){
            cout<<"Yes\n";
        }
        // int ans=1;
        // while(!que.empty()){
        //     int u=que.front();
        //     que.pop();
        //     for(int v:e[u]){
        //         if(--deg[v]==0){
        //             que.push(v);
        //             ans++;
        //         }
        //     }
        // }
        // // cout<<ans<<'\n';
        // if(ans==j) cout<<"Yes\n";
        // else cout<<"No\n";
        init(j);//又忘了复原了
    }
    return 0;
}

