#include <bits/stdc++.h>
using namespace std;
#define double long double
/*

    花几个图可以发现
    新加入一个直线必然会产生+1的贡献
    有交点的情况下，如果交点之前就有，那么没有贡献，否则就加1的贡献
    然后还需要不断地记录交点

*/

struct Line{
    double a,b;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<Line> vec(n+1);
    set<pair<double,double>> st;
    int ans=1;
    for(int i=1;i<=n;i++){
        // cout<<ans<<'\n';
        cin>>vec[i].a>>vec[i].b;
        int sum=1;
        set<pair<double,double>> cur;
        for(int j=1;j<i;j++){
            // cout<<i<<" "<<ans<<'\n';
            if(vec[i].a!=vec[j].a){
                auto [a1,b1]=vec[i];
                auto [a2,b2]=vec[j];
                double x=(b1-b2)/(a2-a1);
                double y=(b1*a2-b2*a1)/(a2-a1);
                if(st.find({x,y})==st.end()){
                    sum++;
                    // cout<<i<<" "<<x<<" "<<y<<'\n';
                    st.insert({x,y});
                }else cur.insert({x,y});
                sum=(sum+cur.size())*2;
            }
        }
        ans+=sum;
    }
    cout<<ans;
    return 0;
}
