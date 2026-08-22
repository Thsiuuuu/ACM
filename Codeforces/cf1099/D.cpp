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
    string s;
    cin>>s;
    s=' '+s;
    vector<ll> a(n+1,0),b(n+1,0),c(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=2;i<=n;i++){
        if(c[i]<c[i-1]){
            cout<<"NO\n";
        }
    }
    if(s[1]=='1'&&a[1]!=c[1]){
        cout<<"NO\n";
        return ;
    }
    a[1]=b[1]=c[1];
    ll cur=c[1];
    int last=1;
    for(int i=2;i<=n;i++){
        if(c[last]!=c[i]){
            ll sum=0;
            for(int k=last+1;k<i;k++){
                if(s[k]=='1'){
                    sum+=a[k];
                }
            }
            ll del=c[i]-c[last];
            for(int k=last+1;k<i;k++){
                if(s[k]=='0'){
                    a[k]=del-sum;
                    break;
                }
            }
        }
        // b[i]=(b[i-1]+a[i]);
    }
    for(int i=last+1;i<=n;i++){
        if(s[i]=='0'){
            a[i]=0;
        }
    }
    for(int i=2;i<=n;i++){
        b[i]=(b[i-1]+a[i]);
        cur=max(cur,b[i]);
        if(cur!=c[i]){
            cout<<"NO\n";
            return ;
        }
    }    
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
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