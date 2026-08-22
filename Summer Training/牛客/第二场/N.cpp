#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+7;
vector<ll> a(N),pre(N);
void solve()
{
    ll n,k;
    cin>>n>>k;
    ll num=0;
    pre[0]=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        num+=a[i];
    }
    if(k<=2) {cout<<num<<'\n';return;}

    ll ans=-1;
    sort(a.begin()+1,a.begin()+1+n);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    if(k%2==1)
    {
        ll x=k/2;
        ll mid=0;
        for(int i=x+1;i+x<=n;i++)
        {
            mid=a[i];
            ll tns=pre[x]+pre[i+x]-pre[i-1];
            ans=max(ans,num+mid*k-tns);
        }
    }
    else
    {
        ll x=k/2-1;
        ll mid=0;
        for(int i=x+2;i+x<=n;i++)
        {
            mid=(a[i]+a[i-1]);
            ll tns=pre[x]+pre[i+x]-pre[i-2];
            ans=max(ans,num+mid*k/2-tns);
        } 
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll e=1;
    cin>>e;
    while(e--) solve();
}