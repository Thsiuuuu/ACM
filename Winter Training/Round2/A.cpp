#include <bits/stdc++.h>
using namespace std;
/*

    不知道怎么想，先想一想什么时候是成立的
    那么肯定是圆心要落在某一个区间内部

    贪心的求区间交集，当前能选一定是最优的

*/

#define double long  double
void sol() {
    int n;
    double r;
    cin>>n>>r;
    vector<pair<double,double>> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i].first>>vec[i].second;
    }
    sort(vec.begin(),vec.end());
    int ans=0;
    double lt=INT64_MIN,rt=INT64_MIN;
    // vector<double> pt;
    for(int i=0;i<n;i++){
        auto [x,y]=vec[i];
        double curl,curr;
        if(y==r){
            curl=curr=x;
        }else{
            double pw=r*r-y*y;
            curl=x-sqrt(pw);
            curr=x+sqrt(pw);
        }
        // cout<<curl<<" "<<curr<<'\n';
        if(curl>rt){
            ans++;
            lt=curl;
            rt=curr;
        }else if(curl<=rt){
            rt=min(rt,curr);
        }
    }
    cout<<ans;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}