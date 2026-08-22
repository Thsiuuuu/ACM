#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#define endl "\n"
#define int long long

using namespace std;

/*


    置换环排序，通过形成若干个独立个置换环，每个置换环进行单独的排序
    最终合并形成整个排好序的数列
    两种计算代价的方法：
        1.第一种通过选取置换环内的最小值用它进行计算
        2.第二种通过选取全局最小值用它进行计算

*/

typedef pair<int,int> pii;
typedef pair<string,int> psi;


int main(){

    int n;
    cin>>n;
    vector<int> w(n);
    for(int i=0;i<n;i++) cin>>w[i];

    vector<int> sorted_w=w;
    sort(sorted_w.begin(),sorted_w.end());

    vector<pair<int,int>> pos(n);
    for(int i=0;i<n;i++) pos[i]={sorted_w[i],i};

    sort(pos.begin(),pos.end());
    vector<bool> visited(n,false);

    int total=0;
    int mn=*min_element(w.begin(),w.end());

    for(int i=0;i<n;i++){
        if(visited[i]) continue;

        vector<int> cycle;
        int cur=i;

        while(!visited[cur]){

            visited[cur]=true;
            cycle.push_back(w[cur]);

            int target=lower_bound(pos.begin(),pos.end(),make_pair(w[cur],0))->second;
            cur=target;

        }


        int cycsize=cycle.size();
        if(cycsize<=1) continue;

        
        int cycsum=0;
        for(auto num:cycle){
            cycsum+=num;
        }

        int cycmin=*min_element(cycle.begin(),cycle.end());

        int cost1=cycsum+(cycsize-2)*cycmin;
        int cost2=cycsum+cycmin+(cycsize+1)*mn;

        total+=min(cost1,cost2);

    }

    cout<<total<<endl;

    return 0;
}