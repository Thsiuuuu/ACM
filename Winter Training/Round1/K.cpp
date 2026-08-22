#include <bits/stdc++.h>
using namespace std;
/*

    想起来暑期集训有一道最小生成树删边的题
    首先想一下哪些点不可能对答案产生影响

    很显然度数k-1的点一定不会对答案产生影响
    所以说就需要删除这些点，同时删除这些点还会导致一些边也无法用到
    所以说这些边所连接的点一定要减去度数，直到所有的点的度数都不小于k-1为止

    答案有两种可能，分别对应情况1和情况2

    对于每一个度数都是k-1的点u，可以假设认为它在大小为k的团中，然后找到所有的邻接点检验每一条边是否存在
    这里可以用vector存边并进行二分查找

    如果发现u不在团中，就删掉u，这么删删到最后
    如果有点，那么这些点的度数都是至少为k的，所以说需要看一下这些点的数量是不是大于k+1的

    对于时间复杂度而言
    可以考虑剪枝，因为情况1对应的完全图需要有k*(k-1)/2>m，如果不满足就不需要枚举团
    所以说当枚举团的时候，有k<=m^(1/2)，
    
    然后对度数不小于k-1的节点个数而言
    不妨设为x，那么有x*(k-1)<=2m
    所以有x<=2m/(k-1)

    然后验证一次的复杂度是O(k^2logm)=O(mklogm)=O(m*(m^(1/2))logm)


*/
#define int long long 
struct Edge{
    int u,v;
    bool operator<(const Edge&other)const{
        if(u==other.u) return v<other.v;
        return u<other.u;
    }
    bool operator!=(const Edge&other)const{
        return u!=other.u||v!=other.v;
    }
};

void sol() {
    int n,m,k;
    cin>>n>>m>>k;

    // vector<Edge> eset;
    vector<int> deg(n+1);
    vector<vector<int>> e(n+1);

    vector<int> visited(n+1,0);

    int number=n;


    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // eset.push_back({u,v});
        // eset.push_back({v,u});
        
        e[u].push_back(v);
        e[v].push_back(u);

        deg[u]++,deg[v]++;
    }
    queue<int> que;
    for(int i=1;i<=n;i++){
        if(deg[i]<k-1ll){
            que.push(i);
        }
    }

    while(que.size()){
        int cur=que.front();
        que.pop();

        if(visited[cur]) continue;

        visited[cur]=1;
        number--;

        for(int v:e[cur]){
            if(--deg[v]<k-1){
                que.push(v);
            }
        }
    }

    if(number<k){
        cout<<"-1\n";
        return ;
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            sort(e[i].begin(),e[i].end());
            if(deg[i]==k-1){
                que.push(i);
            }
        }
    }

    // sort(eset.begin(),eset.end());
    
    while(que.size()){
        int cur=que.front();
        que.pop();
        
        if(visited[cur]) continue;
        visited[cur]=1;


        vector<int> check;
        for(int v:e[cur]){
            if(!visited[v]){
                check.push_back(v);
            }
        }
        
        
        if(check.size()==k-1ll&&k*(k-1ll)/2ll<=m){
            
            bool flag=false;
            for(int i=0;i<check.size();i++){
                for(int j=i+1;j<check.size();j++){
                    // auto it=lower_bound(eset.begin(),eset.end(),(Edge){check[i],check[j]});
                    if(!binary_search(e[check[i]].begin(),e[check[i]].end(),check[j])){
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }

            if(!flag){
                cout<<"2\n";
                cout<<cur<<" ";
                for(int v:check){
                    cout<<v<<" ";
                }
                cout<<'\n';
                return ;
            }
        }
        for(int v:check){
            if(--deg[v]<=k-1ll){
                que.push(v);
            }
        }

        number--;
        if(number<k){
            cout<<"-1\n";
            return ;
        }
    }
    cout<<"1 "<<number<<'\n';
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<i<<" ";
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


// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <algorithm>
// using std::vector;
// using std::queue;
// using std::sort;
// using std::binary_search;

// /*------------------------------IO------------------------------*/

// int read(){
// 	int x =0; char c =getchar(); bool f =0;
// 	while(c < '0' || c > '9') (c == '-') ? f =1, c =getchar() : c =getchar();
// 	while(c >= '0' && c <= '9') x =(x<<1)+(x<<3)+(48^c), c =getchar();
// 	return (f) ? -x : x;
// }

// void write(const int &x){
// 	if(x/10)
// 		write(x/10);
// 	putchar('0'+x%10);
// }

// /*------------------------------Main------------------------------*/

// int main(){
// 	for(int t =0, T =read(); t < T; ++t){
// 		int n =read(), m =read(), k =read();
// 		vector<vector<int> > E(n);
// 		for(int i =0; i < m; ++i){
// 			int u =read()-1, v =read()-1;
// 			E[u].push_back(v), E[v].push_back(u);
// 		}
// 		vector<int> d(n), vis(n)/*0 表示未访问，1 表示访问，2 表示删除*/;
// 		for(int i =0; i < n; ++i){
// 			d[i] =E[i].size();
// 			sort(E[i].begin(), E[i].end());
// 		}
		
// 		queue<int> que;
// 		for(int i =0; i < n; ++i)
// 			if(d[i] < k){
// 				que.push(i);
// 				vis[i] =1;
// 			}
// 		vector<int> cilque;
// 		while(!que.empty() && cilque.empty()){
// 			int u =que.front();
// 			que.pop();
// 			vis[u] =2;
			
// 			if(1ll*(k-1)*k/2 <= m && d[u] == k-1 && cilque.empty()){
// 				cilque.push_back(u);
// 				for(int v:E[u])
// 					if(vis[v] != 2)
// 						cilque.push_back(v);
// 				bool OK =1;
// 				for(int v:cilque){
// 					for(int w:cilque){
// 						if(v == w)/*一条无向边仅判一次*/
// 							break;
// 						else if(!binary_search(E[v].begin(), E[v].end(), w)){
// 							OK =0;
// 							break;
// 						}
// 					}
// 					if(!OK)
// 						break;
// 				}
// 				if(!OK)
// 					cilque.clear();
// 			}
			
// 			for(int v:E[u])
// 				if(--d[v] == k-1 && vis[v] == 0){
// 					vis[v] =1;
// 					que.push(v);
// 				}
// 		}
		
// 		if(!cilque.empty()){
// 			putchar('2'), putchar('\n');
// 			for(int u:cilque)
// 				write(u+1), putchar(' ');
// 			putchar('\n');
// 		}
// 		else if(count(vis.begin(), vis.end(), 0) > 0){
// 			vector<int> ans;
// 			for(int i =0; i < n; ++i)
// 				if(vis[i] == 0)
// 					ans.push_back(i);
// 			putchar('1'), putchar(' '), write(ans.size()), putchar('\n');
// 			for(int u:ans)
// 				write(u+1), putchar(' ');
// 			putchar('\n');
// 		}
// 		else
// 			putchar('-'), putchar('1'), putchar('\n');
// 	}
// }
