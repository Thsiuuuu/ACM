#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N=5e5+1;
vector<int> num(N,0),pep(N,0);//每个学科最多有多少个班级，每个学科有多少可动老师

bool check(int n,int m){
    int cur=(int)0;
    for(int i=1;i<=m;i++){
        int mn=min(num[i]-n,pep[i]);
        cur+=mn;
    }
    if(cur<n) return false;
    else return true; 
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),b(n+1),c(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        num[a[i]]+=b[i];
        if(c[i]==1) pep[a[i]]++;
    }
    int mn=1145141919;//找课程的上界
    for(int i=1;i<=m;i++){
        mn=min(num[i],mn);
    }
    int l=0,r=mn;
    int mid;//二分班主任人数
    int ans;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid,m)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}