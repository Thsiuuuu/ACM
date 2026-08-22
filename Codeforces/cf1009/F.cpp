#include <bits/stdc++.h>
using namespace std;

/*

    不难想到按照二进制分解的长度去贪心拆
    但是需要合并，比如横轴长度为1的条，纵轴上面的任意一段都被迫的去拆
    横轴长度为2的条，纵轴上面的任意一段都被迫的去拆...
    每一段横纵轴上面的长度都是已经由它的起始坐标和终止坐标唯一确定了的
    每次的长度一定只会出现在当前区域的两侧
    代码是转圈去算每一段的贡献的

*/
 
using ll = int64_t;
 
void solve(){
	ll lx, rx, ly, ry;
	cin >> lx >> rx >> ly >> ry;
	ll ans = 0;
	while(true){
		if(lx == rx || ly == ry) break;
		if(lx & 1){
			ans += (ry - ly);
			lx += 1;
		}
		if(lx == rx || ly == ry) break;
		if(rx & 1){
			ans += (ry - ly);
			rx -= 1;
		}
		if(lx == rx || ly == ry) break;
		if(ly & 1){
			ans += (rx - lx);
			ly += 1;
		}
		if(lx == rx || ly == ry) break;
		if(ry & 1){
			ans += (rx - lx);
			ry -= 1;
		}
		if(lx == rx || ly == ry) break;
		lx /= 2; rx /= 2; ly /= 2; ry /= 2;
	}
	cout << ans << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}