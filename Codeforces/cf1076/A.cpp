#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n,s,x;
    cin>>n>>s>>x;
    vector<int>a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    // cout<<sum<<'\n';
    if(sum>s){
        cout<<"No\n";
    }else if((s-sum)%x==0){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
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