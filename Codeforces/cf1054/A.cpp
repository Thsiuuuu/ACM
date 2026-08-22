#include <iostream>
using namespace std;

int t;

void sol(){
	int n;
	cin>>n;
	int ans=0;
	int cnt1=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(!x){
			ans+=1;
		}
		if(x==-1){
			cnt1++;
		}
	}
	if(cnt1&1){
		ans+=2;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>t;
	while(t--){ 
		sol();
	} 
	return 0;
}