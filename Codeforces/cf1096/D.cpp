#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
void sol() {
    int n;cin>>n;
    vector<int> a(2*n);
    int idx1=0,idx2=0,mx=0;
    for(int i=0;i<2*n;i++){
        cin>>a[i];
        if(!a[i]){
            if(idx1) idx2=i;
            else idx1=i;
        }
    }
    set<int> s1,s2,s3;
    bool f1,f2,f3;
    f1=f2=f3=true;
    for(int i=0;idx1+i<2*n&&idx1-i>=0;i++){
        if(a[idx1+i]==a[idx1-i]) s1.insert(a[idx1+i]);
        else{break;}
    }
    for(int i=0;idx2+i<2*n&&idx2-i>=0;i++){
        if(a[idx2+i]==a[idx2-i]) s2.insert(a[idx2+i]);
        else{break;}
    }
    for(int i=0;idx1+i<=idx2-i;i++){
        if(a[idx1+i]==a[idx2-i]) s3.insert(a[idx1+i]);
        else{f3=false;break;}
    }
    if(f3){
        for(int i=1;idx1-i>=0&&idx2+i<2*n;i++){
            if(a[idx1-i]==a[idx2+i]) s3.insert(a[idx1-i]);
            else break;
        }
    }
    // for(auto x:s1) cout<<x<<" ";
    // cout<<'\n';
    // for(auto x:s2) cout<<x<<" ";
    // cout<<'\n';
    // for(auto x:s3) cout<<x<<" ";
    if(f1){
        int cur=0;
        for(int i=0;i<n;i++){
            if(s1.find(i)!=s1.end()){
                cur++;
            }else break;
        }
        mx=max(cur,mx);
    }
    if(f2){
        int cur=0;
        for(int i=0;i<n;i++){
            if(s2.find(i)!=s2.end()){
                cur++;
            }else break;
        }
        mx=max(cur,mx);
    }
    if(f3){
        int cur=0;
        for(int i=0;i<n;i++){
            if(s3.find(i)!=s3.end()){
                cur++;
            }else break;
        }
        mx=max(cur,mx);
    }
    cout<<mx<<'\n';
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