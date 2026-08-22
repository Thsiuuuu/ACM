#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 

struct node{
    int x,y;
    bool operator==(const node&other)const{
        if(x==other.x) return y<other.y;
        return x<other.x;
    }
};

void sol() {
    int n;
    cin>>n;
    vector<node> a(n),b(n);

    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        b[i].x=a[i].x,b[i].y=a[i].y;
    }
    sort(a.begin(),a.end(),[&](const node&f1,const node&f2){
        return f1.x<f2.x;
    });
    sort(b.begin(),b.end(),[&](const node&f1,const node&f2){
        return f1.y<f2.y;
    });
    vector<vector<node>> p(4);
    vector<int> dir(4),len(4);
    int left=a[0].x,right=a[n-1].x,down=b[0].y,up=b[n-1].y;
    int cur=0;
    while(cur<n&&a[cur].x==left){
        p[0].push_back(a[cur++]);
    }
    dir[0]=((cur==n)?1:(a[cur].x-left))*(up-down+1);
    len[0]=((cur==n)?1:(a[cur].x-left));
    cur=n-1;
    while(cur>=0&&a[cur].x==right){
        p[2].push_back(a[cur--]);
    }
    dir[2]=((cur==-1)?1:(right-a[cur].x))*(up-down+1);
    len[2]=((cur==-1)?1:(right-a[cur].x));
    cur=0;
    while(cur<n&&b[cur].y==down){
        p[1].push_back(b[cur++]);
    }
    dir[1]=((cur==n)?1:(b[cur].y-down))*(right-left+1);
    len[1]=((cur==n)?1:(b[cur].y-down));
    cur=n-1;
    while(cur>=0&&b[cur].y==up){
        p[3].push_back(b[cur--]);
    }
    dir[3]=((cur==-1)?1:(up-b[cur].y))*(right-left+1);
    len[3]=((cur==-1)?1:(up-b[cur].y));


    int sub=0;
    for(int i=0;i<=3;i++){
        if(p[i].size()!=1) continue;
        if(p[(i-1+4)%4].size()==1){
            if(p[(i+3)%4][0]==p[i][0]){
                sub=max(sub,dir[i]+dir[(i+3)%4]-len[i]*len[(i+3)%4]);
            }
        }
        if(p[(i+1)%4].size()==1){
            if(p[(i+1)%4][0]==p[i][0]){
                sub=max(sub,dir[i]+dir[(i+1)%4]-len[i]*len[(i+1)%4]);
            }
        }
        sub=max(sub,dir[i]);
    }
    cout<<((right-left+1)*(up-down+1)-sub)<<'\n';
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