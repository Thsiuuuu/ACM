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
    int n,k;
    while(cin>>n>>k){
        vector<vector<int>> a(n);
        vector<int> cnt(k+1,0);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            for(int j=0;j<x;j++){
                int num;
                cin>>num;
                a[i].push_back(num);
            }
        }
        int ans=INT32_MAX;
        int tot=k,all=0;
        bool f=false;
        for(int l=0,r=0;l<n;){
            int num=0;
            while(tot&&num!=n){
                for(int i=0;i<a[r].size();i++){
                    if(++cnt[a[r][i]]==1) tot--;
                    all++;
                }
                num++;
                r=(r+1)%n;
            }
            if(num==n&&tot){
                cout<<"-1\n";
                f=true;
                break ;
            }
            ans=min(ans,all);
            // cout<<l<<' '<<all<<'\n';
            for(int i=0;i<a[l].size();i++){
                if(--cnt[a[l][i]]==0) tot++;
                all--;
            }
            l++;            
        }
        if(!f)  cout<<ans<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}