#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*


    这个只能说瞎猫撞死耗子了

	正解是按位拆解，1和0的分布总共有四种情况，但是2个1 1个0的情况是不合题意的，所以检测这个就行


*/
void sol(){
	int a,b,c;
	cin>>a>>b>>c;
	if((a&b)==(b&c)&&((b&c)==(a&c))) cout<<"yes\n";
	else cout<<"no\n";
} 

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--) sol();
	return 0;
}