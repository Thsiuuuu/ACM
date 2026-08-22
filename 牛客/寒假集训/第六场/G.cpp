#include <bits/stdc++.h>
using namespace std;
#define ll long long  

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    ll n,m,l;
    cin>>n>>m>>l;
    vector<ll> x(n+1,0),y(m+1,0);
    for(int i=1;i<=n;i++){
        cin>>x[i];
        x[i]+=x[i-1];
    }
    for(int i=1;i<=m;i++){
        cin>>y[i];
    }
    ll lt=0,rt=l;
    for(int i=1;i<=m;i++){
        auto i1=upper_bound(x.begin()+1,x.end(),lt);
        auto i2=upper_bound(x.begin()+1,x.end(),rt);
        if(i1!=i2&&(*i1!=rt)){
            cout<<"YES\n";
            return 0;
        }
        lt+=y[i];
        rt+=y[i];
    }
    auto i1=upper_bound(x.begin()+1,x.end(),lt);
    auto i2=upper_bound(x.begin()+1,x.end(),rt);
    if(i1!=i2&&(*i1!=rt)){
        cout<<"YES\n";
        return 0;
    }
    cout<<"NO\n";
    return 0;
}