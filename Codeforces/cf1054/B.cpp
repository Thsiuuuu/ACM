#include <iostream>
#include <algorithm>
using namespace std;

#define int long long  
int t;

void sol(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int mn=-1145141919;
	for(int i=0;i<n;i+=2){
		mn=max(mn,a[i+1]-a[i]);
	}
	cout<<mn<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>t;
	while(t--){ 
		sol();
	} 
	return 0;
}