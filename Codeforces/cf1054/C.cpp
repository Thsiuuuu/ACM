#include <iostream>
#include <algorithm>
using namespace std;

#define int long long  
int t;

void sol(){
	int n,k;
	cin>>n>>k;
	int ans;
	vector<int> cnt(n+1,0);
	int ev=0,low=k;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		cnt[x]++;
		if(cnt[x]==1&&x<k){
			low--;
		}else if(x==k){
			ev++;
		}
	}
	cout<<max(ev,low)<<'\n';
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