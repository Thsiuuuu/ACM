#include <bits/stdc++.h>
using namespace std;
/*

    进行按位拆解，如果某一位上有奇数个1，那么怎么分都没办法让这一位变成0
    如果某一位上有偶数个1，那么只有每一段有偶数个1才可以保证最终为0

    从前缀异或和的角度出发，如果对每一个切割点而言，如果某一段出现了奇数个1，那么最终这一位也会带上1
    如果全都是0，这一位最终就是0
    所以希望sum|p_i最小,sum表示所有位置上有奇数个1的代数和
    通过表示每个mask可以分成几段，然后反向更新每一段的最少代价是多少

*/

#define ll long long 

void sol() {
    ll n;
    cin>>n;
    vector<ll> v(n+1,0),pre(n+1,0);
    
    ll sum=0,huo=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        sum^=v[i];
        huo|=v[i];
        v[i]^=v[i-1];
    }
    vector<int> f(1LL<<20+1);
    for(int i=1;i<=n;i++){
        v[i]-=(v[i]&sum);
    }
    for(int i=1;i<n;i++){
        f[v[i]]++;
    }
    for(int i=0;i<=20;i++){
        for(int j=0;j<(1LL<<20);j++){
            if(j>>i&1){
                f[j]+=f[j^(1LL<<i)];
            }
        }
    }
    vector<int> res(n+1,huo);
    for(int i=0;i<(1LL<<20);i++){
        res[f[i]+1]=min(res[f[i]+1],i);
    }
    res[1]=0;
    for(int i=n-1;i>=1;i--) res[i]=min(res[i],res[i+1]);
    for(int i=1;i<=n;i++) cout<<res[i]+sum<<" ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}