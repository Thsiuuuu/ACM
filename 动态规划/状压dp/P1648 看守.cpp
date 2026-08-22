#include <bits/stdc++.h>
using namespace std;
/*

    把曼哈顿距离转化成每个点的所有坐标分量加减运算的组合之差，然后枚举每一种组合下最大值和最小值之差，取最大值就可以
    总时间复杂度O(nd(2^d))

*/

const int N=1e6+10;


void sol() {
    int n,d;
    cin>>n>>d;

    vector<vector<int>> a(n,vector<int>(d,0));
    vector<int> cal;
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin>>a[i][j];
        }
    }
    int mx=-1;
    for(int mask=0;mask<=(1<<d)-1;mask++){
        cal.assign(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<d;j++){
                if(mask&(1<<j)){
                    cal[i]+=a[i][j];
                }else{
                    cal[i]-=a[i][j];
                }
            }
        }
        mx=max(mx,*max_element(cal.begin(),cal.end())-*min_element(cal.begin(),cal.end()));
    }
    cout<<mx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}