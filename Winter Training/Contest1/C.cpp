#include <bits/stdc++.h>
using namespace std;
/*


    诈骗题

    解法1：
        欧拉公式：V+F-E=2, V,F,E分别为顶点，面，边的数量

        算每个面的贡献和边的数量，满足3F<=2E，当每个面都有3个边的时候，满足E=3V-6

    解法2:
        手玩几组样例发现，相当于一个三角形里面垂着一些点，每次新加一个点相当于多加了3条边
        满足递推关系，最后得出E=3V-6

    情况复杂，去想什么样是可以的，多手玩几组样例，去找找规律


*/

#define int long long 
struct Point{
    int x,y;

    Point(int x_=0,int y_=0):x(x_),y(y_){

    }

    Point operator+(const Point&other)const{
        return Point(x+other.x,y+other.y);
    }
    Point operator-(const Point&other)const{
        return Point(x-other.x,y-other.y);
    }
    
};

struct Edge{
    Point u,v;
    
};

int operator*(const Point&A,const Point&B){
    return A.x*B.x+A.y+B.y;
}

// int cross()

void sol() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> e(n+1);
    vector<Point> st(n+1);
    for(int i=1;i<=n;i++){
        cin>>st[i].x>>st[i].y;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(m==3*n-6){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    // if(n>4){
    //     cout<<"NO";
    // }else if(n==3){
    //     int cnt=0;
    //     for(int i=1;i<=n;i++){
    //         if(e[i].size()==2){
    //             cnt++;
    //         }
    //     }
    //     if(cnt==3){
    //         cout<<"YES";
    //     }else{
    //         cout<<"NO";
    //     }
    // }else{

    //     int cnt=0;
    //     for(int i=1;i<=n;i++){
    //         if(e[i].size()>=2){
    //             cnt++;
    //         }
    //     }
    //     // cout<<cnt<<'\n';
    //     if(cnt<n){
    //         cout<<"NO";
    //         return ;
    //     }

    //     // vector<Edge> eset;
    //     // for(int i=1;i<=n;i++){
    //     //     for(int j=i+1;j<=n;j++){
    //     //         eset.push_back({i,j});
    //     //     }
    //     // }
    //     // for(auto edge:eset){
    //     //     auto [u,v]=edge;
    //     //     Point cur1=u,cur2=v;
    //     //     for(int i=1;i<=n;i++){
    //     //         if(i!=u&&i!=v){
    //     //             if(cur1==u){
    //     //                 cur1=i;
    //     //             }else cur2=i;
    //     //         }
    //     //     }


    //     // }
    //     int mnh=INT64_MAX,mxh=INT64_MIN,l=INT32_MAX,r=INT64_MIN;
    //     for(int i=1;i<=n;i++){
    //         mnh=min(st[i].y,mnh);
    //         mxh=max(st[i].y,mxh);
    //         l=min(st[i].x,l);
    //         r=max(st[i].x,r);
    //     }

    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=n;j++){
    //             for(int k=1;k<=n;k++){
    //                 if(i==j||j==k||i==k){
    //                     continue;
    //                 }
    //                 Point ik=st[i]-st[k];
    //                 Point jk=st[j]-st[k];
    //                 if((ik.y*jk.x==ik.x*jk.y)&&(ik*jk)){
    //                     cout<<"NO";
    //                     return ;
    //                 }
    //             }
    //         }
    //     }
    //     cnt=0;
    
    //     for(int i=1;i<=n;i++){
    //         // if(st[i].x==l||st[i].x==r||st[i].y==mnh||st[i].y==mxh){
    //         //     cnt++;
    //         // }
    //         if(st[i].x!=l&&st[i].x!=r&&st[i].y!=mnh&&st[i].y!=mxh){
    //             cout<<"YES";
    //             return ;
    //         }
    //     }
    //     cout<<"NO";
    // }
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