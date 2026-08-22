#include <bits/stdc++.h>
using namespace std;
/*

    二分长度?

    首先，如果[l,r+1]是合法的，那么[l+1,r+1],[l,r]一定都是合法的，有一个包含的问题
    一个滑动的窗口需要频繁的移动，可以用双指针，枚举右端点
    双指针，因为插入的一个新点只和图形的末端点，末端点的前一个端点，起始端点有关，所以说可以采用双指针，用一个deque维护
    

*/
#define int long long 
struct Point{
    int x,y;
    Point(int x_=0,int y_=0):x(x_),y(y_){}
    Point operator+(const Point&other)const{
        return Point({x+other.x,y+other.y});
    }
    Point operator-(const Point&other)const{
        return Point({x-other.x,y-other.y});
    }

};

int cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);
}


void sol() {


    // Point a(0,0),b(0,1),c(1,-2);
    // cout<<cross(a,b,c);
    int n;
    cin>>n;
    vector<Point> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i].x>>vec[i].y;
    }

    int l=0ll,r=2ll;
    int ans=0ll;

    deque<int> q;
    q.push_back(0);
    q.push_back(1);
    for(;r<n;r++){
        // q.push_back(r);
        while(q.size()>=2&&(
            cross(vec[q.back()],vec[r],vec[q.front()])>=0||
            cross(vec[q.back()-1],vec[q.back()],vec[r])>=0||
            cross(vec[r],vec[q.front()],vec[q.front()+1])>=0)){
            q.pop_front();
            l++;
        }
        q.push_back(r);
        if(q.size()>2){
            // cout<<r<<" "<<q.size()<<" "<<q.front()<<'\n';
            ans=max(ans,(int)q.size());
        }
    }
    cout<<ans<<'\n';

    // int l=3ll,r=n;
    // int ans=0;
    // while(l<=r){
    //     int mid=(l+r)>>1;
    //     deque<int> que;
    //     for(int i=0;i<mid;i++){
    //         que.push_back(i);
    //     }
    //     bool f1=true;
    //     int j;
    //     for(int i=0;i<=n-mid;i++){
    //         f1=true;
    //         for(int idx=0;idx<que.size();idx++){
    //             if(cross(vec[que[idx]],vec[que[(idx+1)%mid]],vec[que[(idx+2)%mid]])>=0){
    //                 f1=false;
    //                 j=que[idx];//最后一个不合法始端点
    //             }
    //         }
    //         if(f1){
    //             ans=mid;
    //             l=mid+1;
    //             break;
    //         }else{
    //             cout<<mid<<" "<<j<<'\n';
    //             int cur=que.back();
    //             while(que.size()&&(cur+1)<n&&que.front()<=j){
                    
    //                 que.pop_front();
    //                 que.push_back((++cur));
    //             }
    //             i=j;
    //         }
    //     }
    //     if(!f1){
    //         r=mid-1;
    //     }
    // }
    // cout<<ans<<'\n';
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