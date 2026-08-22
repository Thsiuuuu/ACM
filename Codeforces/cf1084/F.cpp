#include <bits/stdc++.h>
using namespace std;
/*

    开多个节点
    每个节点表示：
    选大于等于自己的节点的最优选法，以及最小值
    然后节点之间二分


    想错了
    从大到小递推没有问题，但是是固定k个
    加入元素有两种情况，第一种是不选，那么就是全局最大值；第二种是选，那么就相当于最多可以选不超过y个，需要维护前缀最大值

*/
#define int long long 
#define ll long long 
#define double long double
#define i128 __int128_t
#define pii pair<int,int>

ll ksm(ll a,ll b){
    ll res=1ll;
    while(b){
        if(b&1){
            res=res*a;
        }
        b>>=1;
        a=a*a;
    }
    return res;
}

struct node{
    ll x,y;
    bool operator<(const node&other)const {
        if(y==other.y) return x<other.x;
        return y>other.y;
    }
};

// struct dp{
//     ll sum=0;
//     ll minNumber;
//     bool operator<(const dp&other)const{
//         if(sum==other.sum) return minNumber<other.minNumber;
//         else return sum>
//     }
// };


// struct part{
//     priority_queue<int,vector<int>,greater<int>> pq;
//     int sum=0;
// };


void sol() {
    int n,m;
    cin>>n>>m;
    // vector<part> q(n+1);
    vector<node> becy(n),shop(m);
    // vector<dp> ff(n+2),pre(n+2);
    vector<int> ff(n+2,0),minNumber(n+2,0),f1(n+2,0),f2(n+2,0);
    for(int i=0;i<n;i++) cin>>becy[i].x>>becy[i].y;
    for(int i=0;i<m;i++) cin>>shop[i].x>>shop[i].y;
    ll sum=0;

    sort(becy.begin(),becy.end());
    
    priority_queue<int,vector<int>,greater<int>> q;
    for(int number=n+1,i=0;number>=1;number--){
        // cout<<number<<'\n';
        while(i<n&&becy[i].y>=number-1){
            q.push(becy[i].x);
            sum+=becy[i].x;
            i++;
        } 
        while(q.size()>number){
            sum-=q.top();
            q.pop();
        }
        ff[number]=sum;
        if(q.size()==number)   minNumber[number]=q.top();
        else minNumber[number]=0;
    }
    // for(int i=1;i<=n+1;i++){
    //     cout<<ff[i]<<" "<<minNumber[i]<<'\n';
    // }

    for(int number=1;number<=n+1;number++){
        f1[number]=max(ff[number],f1[number-1]);
        f2[number]=max(ff[number]-minNumber[number],f2[number-1]);
    }
    for(int i=0;i<m;i++){
        cout<<max(f1[n+1],f2[shop[i].y+1]+shop[i].x)<<' ';
    }
    cout<<'\n';

    // for(int i=0;i<n;i++){
    //     cin>>becy[i].x>>becy[i].y;
    //     q[becy[i].y].pq.push(becy[i].x);
    //     q[becy[i].y].sum+=becy[i].x;
    // }
    // for(int i=0;i<m;i++){
    //     cin>>shop[i].x>>shop[i].y;
    // }
    // int mx=-1;
    // while(q[n].pq.size()>=n+1){
    //     q[n].sum-=q[n].pq.top();
    //     q[n].pq.pop();
    // }
    // mx=max(mx,q[n].sum);
    // for(int i=n-1;i>=0;i--){
    //     priority_queue<int,vector<int>,greater<int>> temp=q[i+1].pq;
    //     while(temp.size()){
    //         q[i].pq.push(temp.top());
    //         q[i].sum+=temp.top();
    //         temp.pop();
    //     }
    //     while(q[i].pq.size()>=i+1){
    //         q[i].sum-=q[i].pq.top();
    //         q[i].pq.top();
    //     }
    //     mx=max(mx,q[i].sum);
    // }
    // for(int i=0;i<m;i++){
    //     auto [x,y]=shop[i];
    //     int l=0,r=y,mid,obj=-1;
    //     while(l<=r){
    //         mid=(l+r)>>1;
    //         if(x>=q[mid].pq.top()){
    //             obj=mid;
    //             r=mid-1;
    //         }else{
    //             l=mid+1;
    //         }
    //     }
    //     if(obj==-1){
    //         cout<<mx<<'\n';
    //     }else{
            
    //     }
    // }


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