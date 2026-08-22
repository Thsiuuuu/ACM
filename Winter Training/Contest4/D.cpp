#include <bits/stdc++.h>
using namespace std;
/*
    没开int128导致的

    第一种操作可以通过上一天不满足并且当天满足进行转化，并且进行区间求交集
    第二种操作有两种方法，
        第一种是二分，但是需要确定上界，最大会超过1e18*1e9=1e27，所以要开int128
        第二种是可以继续列方程，分别求出第一次超过左端点和右端点的天数，进行比较，都是上一天不满足，且这一天满足
        如果是同一天超过的左端点和右端点，就说明是唯一的
        否则就不是唯一的

*/
#define int long long 
void sol() {
    int q;
    cin>>q;
    int left=1,right=INT64_MAX;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int a,b,n;
            cin>>a>>b>>n;
            int curl=left,curr=right;
            if(n==1){
                curr=a;
            }else{
                curr=a+(n-1)*(a-b);
                curl=a+(n-2)*(a-b)+1ll;
            }
            if(curr<left||curl>right){
                cout<<"0 ";
            }else{
                right=min(right,curr);
                left=max(left,curl);
                cout<<"1 ";
            }
            // cout<<left<<" "<<right<<'\n';
        }else{
            int a,b;
            cin>>a>>b;
            int l,r;
            l=max(1ll,(left-b-1)/(a-b)+1);
            r=max(1ll,(right-b-1)/(a-b)+1);
            if(l==r){
                cout<<l<<' ';
            }else{
                cout<<"-1 ";
            }
            // int l=1ll,r=1e18;
            // int mid;
            // int ans=-1;
            // while(l<=r){
            //     mid=(l+r)>>1ll;
            //     __int128_t number=(__int128_t)(mid-1ll)*(a-b)+a;
            //     if(number>=left){
            //         ans=mid;
            //         r=mid-1ll;
            //     }else{
            //         l=mid+1ll;
            //     }
            // }
            // if(ans==-1||(__int128_t)(ans-1)*(a-b)+a<right){
            //     cout<<"-1 ";
            // }else{
            //     cout<<ans<<' ';
            // }
        }
    }
    cout<<'\n';
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