#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());//删除重复元素的开头到结尾
    if(a.size()==1) cout<<"NO";
    else  cout<<a[1];
    return 0;
}