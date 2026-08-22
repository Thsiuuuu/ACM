#include <bits/stdc++.h>
using namespace std;
/*

    一个复杂度非常奇怪的做法
    首先区间查询问题可以用根号分治
    如果<=sqrt(n),可以直接查，统计频数，单次时间复杂度O(sqrt(n)*logn)，预处理时间复杂度O(nlogn)
    如果>sqrt(n)，用map存下每一个频数>sqrt(n)/3的数字的所有出现下标，预处理时间复杂度O(n*logn*logn)，每次查询枚举所有可能元素对[l,r]二分l和r，然后作差进行判断，时间复杂度O(6*sqrt(n)logn+logn)
    所以总的时间复杂度O(nlogn+n*logn*logn+sqrt(n)logn)

*/

void sol() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    map<int,int> number;
    map<int,vector<int>> vec;
    int lim=sqrt(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        number[a[i]]++;
    } 

    for(int i=1;i<=n;i++){
        if(number[a[i]]>=lim/3){
            vec[a[i]].push_back(i);
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        set<int> ans;
        int len=r-l+1;
        if(len<=lim){
            for(int i=l;i<=r;i++){
                if(number[a[i]]>len/3){
                    ans.insert(a[i]);
                }
            }
        }else{
            for(auto [key,val]:vec){
                auto i1=upper_bound(val.begin(),val.end(),r);
                auto i2=lower_bound(val.begin(),val.end(),l);
                if(i1-i2>len/3){
                    ans.insert(key);
                }
            }
        }
        if(ans.size()==0) cout<<"-1\n";
        else{
            for(int x:ans) cout<<x<<" ";
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