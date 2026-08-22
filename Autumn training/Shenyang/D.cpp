#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,k,a,b;
    cin>>n>>k>>a>>b;
    vector<int> arr;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            arr.push_back(2*i*(j-i)+(j-i)*(j-i)+2*(b/a)*(j-i));
        }
    }
    sort(arr.begin(),arr.end());
    cout<<arr[k-1]<<'\n';
    return 0;
}