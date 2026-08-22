#include <bits/stdc++.h>
using namespace std;
/*

    等差数列差分，做两遍前缀和可以得到
*/

#define int long long 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;

    cin>>n>>m;
    vector<int> del(n+3,0);
    while(m--){
        int l,r,s,e;
        cin>>l>>r>>s>>e;
        int d=(e-s)/(r-l);
        del[l]+=s;
        del[l+1]+=d-s;
        del[r+1]-=d+e;
        del[r+2]+=e;
    }

    int ans=0,mx=-1145141919810;
    for(int i=1;i<=n;i++){
        del[i]+=del[i-1];
    }
    for(int i=1;i<=n;i++){
        del[i]+=del[i-1];
    }
    for(int i=1;i<=n;i++){
        ans^=del[i];
        mx=max(mx,del[i]);
    }
    cout<<ans<<" "<<mx;
    return 0;
}