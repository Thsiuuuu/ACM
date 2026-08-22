#include <bits/stdc++.h>
using namespace std;
/*

    dp[i][j],j=0表示转移到下端点，j=1表示转移到上端点

    手玩发现，转移总共就4中情况，分别用1,0代替较高点和较低点，1->0,0->1,1->1,0->0，其他的转移相当于进行向量合并，可以转化为上面四种情况之一，所以dp就可以

*/
#define int long long
struct Point{
    int x,y;
    Point(int x_=0,int y_=0):x(x_),y(y_){}
    bool operator<(const Point&other)const{
        if(x==other.x){
            return y<other.y;
        }
        return x<other.x;
    }

};

void sol() {
    int n,ax,ay,bx,by;
    cin>>n>>ax>>ay>>bx>>by;
    vector<Point> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].x;
    }
    for(int i=0;i<n;i++){
        cin>>p[i].y;
    }
    sort(p.begin(),p.end());
    map<int,vector<Point>> mp;
    for(int i=0;i<n;i++){
        int j=i;
        while(j<n&&p[j].x==p[i].x){
            j++;
        }
        j=j-1;
        mp[p[i].x].push_back(p[i]);
        mp[p[i].x].push_back(p[j]);//0下,1上
        // cout<<mp[p[i].x][0].x<<" "<<mp[p[i].x][0].y<<'\n';
        i=j;
    }
    // for(auto [key,vec]:mp){
    //     cout<<key<<" "<<vec[0].x<<" "<<vec[0].y<<" "<<vec[1].x<<" "<<vec[1].y<<'\n';
    // }
    vector<array<int,2>> dp(mp.size(),{0,0});
    
    dp[0][0]=llabs(mp[p[0].x][1].y-ay)+llabs(mp[p[0].x][1].y-mp[p[0].x][0].y)+llabs(mp[p[0].x][0].x-ax);
    dp[0][1]=llabs(mp[p[0].x][0].y-ay)+llabs(mp[p[0].x][1].y-mp[p[0].x][0].y)+llabs(mp[p[0].x][0].x-ax);
    int cur=1;
    for(auto [key,vec]:mp){
        if(key==p[0].x){
            continue;
        }
        auto it=mp.lower_bound(key);
        it--;
        int la=it->first;
        vector<Point> lav=it->second;
        dp[cur][0]=min(dp[cur-1][0]+llabs(lav[0].y-vec[1].y),dp[cur-1][1]+llabs(lav[1].y-vec[1].y))+llabs(lav[0].x-vec[1].x)+llabs(vec[0].y-vec[1].y);
        dp[cur][1]=min(dp[cur-1][0]+llabs(lav[0].y-vec[0].y),dp[cur-1][1]+llabs(lav[1].y-vec[0].y))+llabs(lav[0].x-vec[1].x)+llabs(vec[0].y-vec[1].y);
        cur++;
    }
    cout<<min(dp[mp.size()-1][0]+llabs(mp[p[n-1].x][0].y-by)+llabs(mp[p[n-1].x][0].x-bx),dp[mp.size()-1][1]+llabs(mp[p[n-1].x][1].y-by)+llabs(mp[p[n-1].x][1].x-bx))<<'\n';
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