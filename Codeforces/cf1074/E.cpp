#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
void sol() {
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> b(m);
    string s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    cin>>s;

    
    int mx=INT64_MIN,mn=INT64_MAX;
    int cur=0;
    map<int,int> mp;
    for(int i=0;i<k;i++){
        if(s[i]=='L'){
            cur--;
        }else{
            cur++;
        }
        if(mp.find(cur)==mp.end()){
            mp[cur]=i+1;
        }
        mx=max(cur,mx);
        mn=min(cur,mn);
    }

    // cout<<mn<<" "<<mx<<'\n';
    
    vector<int> diff(k+3,0);
    sort(b.begin(),b.end());
    // cout<<(*b.begin())<<'\n';
    for(int i=0;i<n;i++){
        auto it=lower_bound(b.begin(),b.end(),a[i]);
        // int cit=*it;
        int l=-1145141919810,r=-l;
        
        // cout<<"hel\n";
        if(it!=b.begin()){
            // cout<<"hel\n";
            l=*prev(it);
        }
        if(it!=b.end()){
            r=*it;
        }
        // int adl=0,adr=k+1;
        int t=k+1;
        
        // cout<<"l "<<l<<"\nr "<<r<<'\n';
        if(a[i]+mx>=r){
            t=min(t,mp.find(r-a[i])->second);
        }
        if(a[i]+mn<=l){
            t=min(t,mp.find(l-a[i])->second);
        }
        // cout<<t<<"\n";
        // adr=t;
        diff[0]++,diff[t]--;
    }
    // cout<<'\n';
    for(int i=1;i<=k;i++){
        diff[i]+=diff[i-1];
        cout<<diff[i]<<" ";
    }
    cout<<'\n';
}

signed  main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}