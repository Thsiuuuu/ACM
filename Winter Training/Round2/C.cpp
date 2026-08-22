#include <bits/stdc++.h>
using namespace std;
/*

    切比雪夫距离转化为曼哈顿距离
    这个距离是相当于对每一个点而言，其他点到它距离的切比雪夫距离的和
    但是切比雪夫距离求最大值不好转化
    可以转化成曼哈顿距离

    (x,y)->(x+y,x-y)，原坐标的曼哈顿距离=新坐标的切比雪夫距离
    (x,y)->((x+y)/2,(x-y)/2)，原坐标的切比雪夫距离=新坐标的曼哈顿距离

    就可以看成是经过变换之后对曼哈顿距离进行求和
    拆绝对值之后发现可以通过排序+前缀和快速得到

    因为/2可能会导致浮点误差，所以可以先不/2，最后再/2
    这里还需要注意一下记录每个横坐标对应的纵坐标的索引

*/
#define int long long 
void sol() {
    
    int n;
    cin>>n;
    vector<pair<int,int>> x(n+1),y(n+1);
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        x[i].first=a+b;
        y[i].first=a-b;
        x[i].second=y[i].second=i;
    }
    sort(x.begin()+1,x.end());
    sort(y.begin()+1,y.end());
    
    vector<int> trans(n+1);
    for(int i=1;i<=n;i++){
        auto [val,idx]=y[i];
        trans[idx]=i;
    }

    vector<int> prex(n+1,0),prey(n+1,0);
    for(int i=1;i<=n;i++){
        prex[i]=x[i].first+prex[i-1];
        prey[i]=y[i].first+prey[i-1];
    }
    int ans=INT64_MAX;
    for(int i=1;i<=n;i++){
        // auto it=lower_bound(y.begin()+1,y.end());
        int j=trans[x[i].second];
        int dx=(2*i-n)*x[i].first-(prex[i]-prex[0])+(prex[n]-prex[i]);
        int dy=(2*j-n)*y[j].first-(prey[j]-prey[0])+(prey[n]-prey[j]);
        ans=min(ans,dx+dy);
    }
    cout<<ans/2;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}