#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

void sol() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<vector<int>> stg(n+1,vector<int>(23,1)),stm(n+1,vector<int>(23,INT32_MIN));
    vector<int> block(33,0),ls,rs; ls=rs=block;
    rs[32]=n;
    int idx=32,last=a[n];
    for(int i=n;i>=1;i--){
        stg[i][0]=a[i],stm[i][0]=b[i];
        ll cur=gcd(a[i],last);
        if(cur<last){
            block[idx]=last;
            ls[idx]=i+1;
            rs[idx-1]=i;
            idx--;
        }
        last=cur;
        for(int j=1;j<=23&&(i+(1ll<<j)-1<=n);j++){
            stg[i][j]=gcd(stg[i][j-1],stg[i+(1<<(j-1))][j-1]);
            stm[i][j]=max(stm[i][j-1],stm[i+(1<<(j-1))][j-1]);
        }
    }
    ls[idx]=1,block[idx]=last;
    // for(int i=1;i<=32;i++){
    //     cout<<ls[i]<<" "<<rs[i]<<" "<<block[i]<<'\n';
    // }
    while(q--){
        int l,r;
        cin>>l>>r;
        ll rem=0,ans=0;
        for(int i=1;i<=32;i++){
            if(l>rs[i]||r<ls[i]) continue;
            int rr=min(r,rs[i]),lf=max(l,ls[i]);
            int len=rr-lf+1;
            int k=log2(len),mx=max(stm[lf][k],stm[rr-(1ll<<k)+1][k]);
            if(mx-rem>0){
                ans+=((mx-rem+block[i]-1)/block[i]);
                rem+=((mx-rem+block[i]-1)/block[i]*block[i]);
            }
        }
        cout<<ans<<'\n';
    }
}


signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}