#include <bits/stdc++.h>
using namespace std;
/*

    如果l=r，那么就直接输出
    如果r是10的幂次，就输出r-1
    否则尽可能变成9

*/

#define ll long long 

void sol() {
    
    ll l,r;
    cin>>l>>r;
    auto t=to_string(r);
    if(l==r){
        ranges::reverse(t);
        cout<<stoll(t)<<'\n';
    }else{
        if(count(t.begin(),t.end(),'0')==t.size()-1&&t[0]=='1'){
            cout<<r-1<<'\n';
        }else{
            ll ans=stoll("1"+string(t.size()-1,'0'));
            ans=max(ans,l);
            auto s=string(18,'0')+to_string(ans);
            for(ll i=1,j=s.size()-1;i<=1e16;i*=10,j--){
                for(int k=1;k<='9'-s[j];k++){
                    if(ans+i<=r) ans+=i;
                }
            }
            s=to_string(ans);
            ranges::reverse(s);
            cout<<s<<'\n';
        }
    }

    // string l,r;
    // cin>>l>>r;
    // if(l==r){
    //     int n=l.size();
    //     int last;
    //     for(int i=n-1;i>=0;i--){
    //         if(l[i]!='0'){
    //             last=i;
    //             break;
    //         }
    //     }
    //     reverse(l.begin(),l.begin()+last+1);
    //     cout<<l.substr(0,last+1)<<'\n';
    // }else if(r[0]!='0'&&count(r.begin(),r.end(),'0')==r.size()-1){
    //     int n=r.size()-1;
    //     if(r[0]==1){
    //         n--;
    //     }
    //     for(int i=0;i<n;i++){
    //         cout<<'9';
    //     }
    //     if(r[0]!='1'){
    //         cout<<(char)(r[0]-1);
    //     }
    //     cout<<'\n';
    // }else{
    //     int n=r.size();
    //     while(l.size()<n){
    //         l='0'+l;
    //     }
    //     string ans;
    //     bool flag=true;
    //     for(int i=1;i<r.size();i++){
    //         if(r[i]!='9'){
    //             flag=false;
    //             break;
    //         }
    //     }
    //     if(flag){
    //         reverse(r.begin(),r.end());
    //         cout<<r<<'\n';
    //     }else if(r[0]^l[0]){
    //         if(r[0]>'1'){
    //             ans.push_back((char)(r[0]-1));
    //             for(int i=0;i<n-1;i++){
    //                 ans.push_back('9');
    //             }
    //         }else{
    //             int last=0;
    //             for(int i=1;i<n;i++){
    //                 if(r[i]!='0'){
    //                     last=i;
    //                     break;
    //                 }
    //             }
    //             for(int i=0;i<last;i++){
    //                 ans.push_back(r[i]);
    //             }
    //             if(last!=n-1){
    //                 ans.push_back((char)(r[last]-1));
    //                 for(int i=last+1;i<n;i++){
    //                     ans.push_back('9');
    //                 }
    //             }else{
    //                 for(int i=last;i<n;i++){
    //                     ans.push_back(r[i]);
    //                 }
    //             }
    //         }
    //         reverse(ans.begin(),ans.end());
    //         cout<<ans<<'\n';
    //     }else{
    //         int t=0;
    //         while(t<n&&l[t]==r[t]){
    //             t++;
    //         }
    //         if(t==n-1){
    //             ans=r;
    //         }else{
    //             bool f=true;
    //             for(int i=t+1;i<n;i++){
    //                 if(r[i]!='9'){
    //                     f=false;
    //                     break;
    //                 }
    //             }
    //             if(f){
    //                 ans=r;
    //             }else{
    //                 for(int i=0;i<t;i++){
    //                     ans.push_back(r[i]);
    //                 }
    //                 ans.push_back((char)(r[t]-1));
    //                 ans=ans+string(n-t-1,'9');
    //             }
    //         }
    //         reverse(ans.begin(),ans.end());
    //         cout<<ans<<'\n';
    //     }
    // }
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