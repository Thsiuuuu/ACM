#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
/*

    因为答案频率超过了1/3
    一次就有1/3的概率取到答案
    连续取50次的话极大概率会取到正确答案
    所以对于每次取值查一下区间内部有多少个数就可以

*/

const int N=1e6+10;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int n,m,a[N];
void sol() {
    cin>>n>>m;
    gp_hash_table<int,vector<int>> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]].push_back(i);
    }
    for(int i=1,l,r,len,lim;i<=m;i++){
        cin>>l>>r;
        len=r-l+1,lim=len/3;
        vector<int> f(50);
        for(int j=1;j<=50;j++){
            f[j-1]=a[rd()%len+l];
        }
        vector<int> ans;
        for(int j=0;j<50;j++){
            if(upper_bound(mp[f[j]].begin(),mp[f[j]].end(),r)-lower_bound(mp[f[j]].begin(),mp[f[j]].end(),l)>lim){
                ans.push_back(f[j]);
            }
        }
        if(ans.size()==0) cout<<"-1\n";
        else{
            sort(ans.begin(),ans.end());
            ans.erase(unique(ans.begin(),ans.end()),ans.end());
            for(int j=0;j<ans.size();j++){
                cout<<ans[j]<<" ";
            }
            cout<<'\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}