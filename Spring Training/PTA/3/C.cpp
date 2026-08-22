#include <bits/stdc++.h>
using namespace std;
#define ll long long 

struct node{
    int a,b;
    bool operator<(const node&other){
        if(a==other.a) return b<other.b;
        return a<other.a;
    }
};

void sol(){
    int n,k,s;
    cin>>n>>k>>s;
    vector<node> fi(n),sc;
    for(int i=0;i<n;i++){
        cin>>fi[i].a>>fi[i].b;
    }  
    int ans=0;
    sort(fi.begin(),fi.end());
    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(fi[i].a<175) continue;
        if(i==0) ans++;
        else{
            if(fi[i-1].a==fi[i].a){
                if(fi[i].b>=s) ans++;
                else mp[fi[i].a]++;
                // else sc.push_back(fi[i]);
            }else{
                ans++;
            }
        } 
    }
    for(const auto&[key,val]:mp){
        ans+=min(k-1,val);
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}