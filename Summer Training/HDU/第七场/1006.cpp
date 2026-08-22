#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+7;
vector<pair<ll,ll> > a(N);
void solve()
{
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i].first>>a[i].second;
    sort(a.begin()+1,a.begin()+1+m);
    ll al0=1,ar0=1,al1=-1,ar1=-1,al2=-1,ar2=-1;
    ll ff=0;
    for(int i=1;i<=m;i++)
    {
        auto [l,r]=a[i];
        if(l<al1 || al1==-1)
        {
            ar0=l;
            if(ar1==-1) ar1=r;
            else ar1=max(r,ar1);
            if(al1==-1) al1=r;
            else al1=min(r,al1);
            if(ar0>=al1) {cout<<"No\n";return;}
        }
        else if(l<al2 || al2==-1)
        {
            ar1=l;
            if(ar2==-1) ar2=r;
            else ar2=max(r,ar2);
            if(al2==-1) al2=r;
            else al2=min(r,al2);
            if(ar1>=al2) {cout<<"No\n";return;}
        }
        else {cout<<"No\n";return;}
    }
    if(ar1==n) {cout<<"No\n";return;}
    if(al2==-1) al2=n;
    cout<<"Yes\n";
    cout<<al1<<' '<<al2<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll e=1;
    cin>>e;
    while(e--) solve();
}