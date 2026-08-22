#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const ll mod=1e9+7;
ll ksm(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1,a=a*a%mod;
	}
	return res;
}

void sol(){
	int n;
	cin>>n;
	vector<ll> a(n+1,0),p;
	p=a;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>p[i];
	vector<ll> g(1024,0),f(1024,0);
	f[0]=1;
	
	ll base=ksm(10000,mod-2);
	for(int i=1;i<=n;i++){
		for(int number=0;number<=1023;number++){
			g[number^a[i]]=(g[number^a[i]]+f[number]*p[i]%mod*base%mod)%mod;
			g[number]=(g[number]+f[number]*(1-p[i]*base%mod+mod)%mod)%mod;
		}
		f=g;
		g.assign(1024,0);
	}
	ll res=0;
	for(int i=0;i<=1023;i++){
		res=(res+(i*i%mod)*f[i]%mod)%mod;
	}
	cout<<res<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t=1;
	cin>>t;
	while(t--){
		sol();
	}
	return 0;
}