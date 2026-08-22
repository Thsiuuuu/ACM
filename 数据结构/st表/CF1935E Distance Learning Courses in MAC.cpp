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
    int n;cin>>n;
    VL x(n+1,0),y(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    VLL sm(n+1,VL(33,0)),st(n+1,VL(22,0));
    for(int i=1;i<=n;i++){
        for(int j=32;j>=0;j--){
            if(((x[i]>>j)&1)==((y[i]>>j)&1)) st[i][0]|=(((x[i]>>j)&1)<<j);
            else{
                for(int k=j;k>=0;k--){
                    if((y[i]>>k)&1) sm[i][k]++;
                }
                break;
            }
        }
        for(int j=32;j>=0;j--) sm[i][j]+=sm[i-1][j];
    }
    for(int j=1;j<=__lg(n);j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=st[i][j-1]|st[i+(1<<(j-1))][j-1];
        }
    }
    auto qry=[&](int l,int r)->ll{
        int k=__lg(r-l+1);
        return st[l][k]|st[r-(1<<k)+1][k];
    };
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        ll val=qry(l,r);
        ll ans=val;
        for(int i=32;i>=0;i--){
            int w=((val>>i)&1)+(sm[r][i]-sm[l-1][i]);
            if(w>=2){
                ans|=((1<<(i+1))-1);
                break;
            }else if(w==1){
                ans|=(1<<i);
            }
        }
        cout<<ans<<' ';
    }
    cout<<'\n';
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