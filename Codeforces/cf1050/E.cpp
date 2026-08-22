#include <bits/stdc++.h>
using namespace std;
using LL=long long;

void sol(){
    int n,k;
    cin>>n>>k;
    vector<LL> a(n+1),cnt(n+1),lim(n+1),nw(n+1,0);
    LL ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(cnt[a[i]]%k){
            cout<<"0\n";
            return ;
        }
        lim[a[i]]=cnt[a[i]]/k;
    }
    for(int l=1,r=1;l<=n;l++){
        while(r<=n&&nw[a[r]]+1<=lim[a[r]]){
            nw[a[r++]]++;
        }
        ans+=(r-l);
        nw[a[l]]--;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--)  sol();
    return 0;
}