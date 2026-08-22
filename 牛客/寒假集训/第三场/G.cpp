#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
void sol() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum1+=a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        sum2+=b[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    if(sum1>sum2){
        int l=0;
        while(l<n&&sum1>sum2){
            sum1-=a[l++];
        }
        cout<<l<<'\n';
    }else if(sum1<sum2){
        int l=0;
        while(l<m&&sum1<sum2){
            sum2-=b[l++];
        }
        cout<<l<<'\n';
    }else{
        cout<<"1\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}