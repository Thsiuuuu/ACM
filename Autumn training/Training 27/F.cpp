#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*


    补，通过二分区间左右端点，然后作差得到

*/
void sol(){

    int n,d;
    int ans=0;
    cin>>n>>d;
    vector<int> a(n);
    string s;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>s;

    vector<int> tr1,tr2;
    for(int i=0;i<s.size();i++){
        if(s[i]=='-'){
            tr2.push_back(a[i]);
        }else tr1.push_back(a[i]);
    }

    map<int,int> cnt;
    for(int i=0;i<tr2.size();i++) cnt[tr2[i]]++;
    for(int i=0;i<tr1.size();i++){
        auto l=lower_bound(tr2.begin(),tr2.end(),tr1[i]-d);
        auto r=upper_bound(tr2.begin(),tr2.end(),tr1[i]+d);
        ans+=(r-l-cnt[tr1[i]]);
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    sol();
    return 0;
}