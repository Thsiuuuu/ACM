#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define int long long



signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,x;
    cin>>n>>x;

    vector<int> child(n);
    for(int i=0;i<n;i++) cin>>child[i];
    sort(child.begin(),child.end());

    int i=0,j=n-1;
    while(i<j){
        if(child[i]+child[j]<=x){
            i++,j--;
        }else j--;
    }

    cout<<i+(n-2*i);
    return 0;
}