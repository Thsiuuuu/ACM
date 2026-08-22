#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
void sol() {
    string s;
    cin>>s;
    // sort(s.begin(),s.end());
    int n=s.size();
    int sum=0;
    vector<int> b(n,0);
    for(int i=0;i<n;i++){
        if(!i) b[i]=s[i]-'1';
        else b[i]=s[i]-'0';
        sum+=(s[i]-'0');
    }
    sort(b.begin(),b.end(),greater<int>());
    for(int i=0;i<=n;i++){
        if(!i){
            if(sum<=9){
                cout<<i<<'\n';
                return ;
            }
        }else{
            if(sum-b[i-1]<=9){
                cout<<i<<'\n';
                return ;
            }
            sum-=b[i-1];
        }
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