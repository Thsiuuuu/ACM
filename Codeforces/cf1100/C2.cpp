#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
const int N=2e5+10;
ll a[N];
// ll f[N],g[N],a[N];
// bool ff[N],gf[N];
void sol() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    ll pre=0,pf=0;
    ll idx=-1,Mx=sum;
    for(int i=1;i<=n;i++){
        if(a[i]>0){
            if(Mx<sum-pf+pre-2*a[i]){
                idx=i;
                Mx=sum-pf+pre-2*a[i];
            }
        }
        pf+=a[i];
        pre+=llabs(a[i]);
    }
    if(idx==-1){
        cout<<"0\n\n";
        return ;
    }
    VI ans;
    int cnt=0;
    for(int i=idx-1;i>=1;i--){
        if(a[i]>0&&!(cnt&1)){
            cnt++;
            ans.push_back(i);
        }else if(a[i]<0&&(cnt&1)){
            cnt++;
            ans.push_back(i);
        }
    }
    ans.push_back(idx);
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';

    // for(int i=1;i<=n;i++){
    //     ff[i]=gf[i]=f[i]=g[i]=0;
    // }
    // for(int i=1;i<=n;i++){
    //     if(a[i]<0){
    //         f[i]=f[i-1]+a[i];
    //         g[i]=g[i-1]+a[i];
    //     }else{
    //         ll sum1=-(f[i-1]+a[i]),sum2=(g[i-1]+a[i]);
    //         if(sum1>sum2){
    //             gf[i]=1;
    //         }
    //         g[i]=max(sum1,sum2);
    //         sum1=-sum1,sum2=-sum2;
    //         if(sum1>sum2){
    //             ff[i]=1;
    //         }
    //         f[i]=min(sum1,sum2);
    //     }
    // }
    // VI ans;
    // int bit=1;
    // for(int i=n;i>=1;i--){
    //     if(bit==0&&ff[i]){
    //         bit=1;
    //         ans.push_back(i);
    //     }else if(bit==1&&gf[i]){
    //         bit=0;
    //         ans.push_back(i);
    //     }
    // }
    // reverse(ans.begin(),ans.end());
    // cout<<ans.size()<<'\n';
    // for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    // cout<<'\n';
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