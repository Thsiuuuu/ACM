#include <bits/stdc++.h>
using namespace std;

#define int long long 

/*

    出发点，肯定是要整体的数值越来越大，而不是单个的数值越来越大
    从小到大枚举剑
    然后对于每一把剑，如果没有怪兽能打败，就必然被淘汰
    如果能打败奖励不为0的怪兽，那就先打这个：
        对于两把剑都能打败一只怪兽的情况下，先用小的一定最优，分类讨论易证。
    如果说只能打败不为0的怪兽了，那就打这个。
    总的时间复杂度是O(nlogn)


*/
void sol(){
    int n,m;
    cin>>n>>m;
    priority_queue<int,vector<int>,greater<int>> pa,pb0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pb1;
    
    int ans=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        pa.push(a);
    }
    vector<int> b(m),c(m);
    for(int i=0;i<m;i++) cin>>b[i];
    for(int i=0;i<m;i++) cin>>c[i];
    for(int i=0;i<m;i++){
        if(c[i]){
            pb1.push({b[i],c[i]});
        }else{
            pb0.push(b[i]);
        }
    }
    while(pa.size()&&(pb0.size()||pb1.size())){
        // cout<<ans<<'\n';
        int cur=pa.top();
        pa.pop();
        if(pb1.size()&&pb1.top().first<=cur){
            int val=pb1.top().second;
            ans++;
            pb1.pop();
            pa.push(max(val,cur));
        }else{
            if(pb0.size()&&pb0.top()<=cur){
                ans++;
                pb0.pop();
            }//取堆顶一定堆要有元素
        }
        // cout<<pa.size()<<" "<<pb0.size()<<" "<<pb1.size()<<'\n';
    }
    // cout<<"hel\n";
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