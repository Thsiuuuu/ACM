#include <bits/stdc++.h>
using namespace std;

#define ll long long 


int f[12][4097][4097],a[12][12][12];
void sol(){
	int n;cin>>n;
	vector<vector<int>> S(13);
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			for(int z=0;z<n;z++){
				cin>>a[x][y][z];
			}
		}
	}
	for(int i=0;i<(1<<n);i++){
		S[__builtin_popcount(i)].push_back(i);
	}	
	for(int i=0;i<12;i++){	
		for(int j=0;j<4097;j++){
			for(int k=0;k<4097;k++){
				f[i][j][k]=INT32_MAX;
			}
		}
	}
	for(int z=0;z<n;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				for(auto s1:S[z]){
					for(auto s2:S[z]){
						if((s1&(1<<x))==0&&(s2&(1<<y))==0){
							if(!z) f[z][s1|(1<<x)][s2|(1<<y)]=a[x][y][z];
							else f[z][s1|(1<<x)][s2|(1<<y)]=min(f[z][s1|(1<<x)][s2|(1<<y)],f[z-1][s1][s2]+a[x][y][z]);
						}
					}
				}
			}
		}
	}
	cout<<f[n-1][(1<<n)-1][(1<<n)-1];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t=1;
//	cin>>t;
	while(t--){
		sol();
	}
	return 0;
}