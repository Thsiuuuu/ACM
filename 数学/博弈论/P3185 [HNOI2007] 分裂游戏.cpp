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
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
void sol() {
    int n;
    cin>>n;
    int ans=0;
    bool f=false;
    VL all(n),sg(n,0);
    for(int i=0;i<n;i++) cin>>all[i];
    sg[n-1]=0;
    for(int i=n-2;i>=0;i--){
        set<int> s;
        for(int j=i+1;j<n;j++){
            for(int k=j;k<n;k++){
                s.insert(sg[j]^sg[k]);
            }
        }
        for(int x=0;;x++){
            if(s.find(x)==s.end()){
                sg[i]=x;
                break;
            }
        }
    }
    ll S=0;
    for(int i=0;i<n;i++){
        if(all[i]&1) S^=sg[i];
    }
    if(S==0) cout<<"-1 -1 -1\n0\n";
    else{
        for(int i=0;i<n;i++){
            if(all[i]==0) continue; 
            for(int j=i+1;j<n;j++){
                for(int k=j;k<n;k++){
                    if((S^sg[i]^sg[j]^sg[k])==0){
                        if(!f){
                            cout<<i<<" "<<j<<" "<<k<<'\n';
                            f=true;
                        }
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<'\n';    
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