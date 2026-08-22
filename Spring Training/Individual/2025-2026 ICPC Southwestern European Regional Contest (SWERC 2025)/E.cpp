#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define pll pair<ll,ll>
#define double long double

const int N=1010;
int but[N];

void sol() {
    int n,q;
    cin>>n>>q;
    string s;cin>>s;s=' '+s;
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+(s[i]=='4');
    }
    while(q--){
        ll l,r,x,y;
        cin>>l>>r>>x>>y;
        x=llabs(x),y=llabs(y);
        ll len=r-l+1;
        ll lim=2*(r-l+1)+1-pre[r]+pre[l-1];
        if((y+x)>=lim||y>len||x>len) cout<<"no\n";
        else cout<<"yes\n";
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