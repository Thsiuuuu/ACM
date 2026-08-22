#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
#define ll long long 
#define double long double
#define i128 __int128_t
#define pii pair<int,int>

ll ksm(ll a,ll b){
    ll res=1ll;
    while(b){
        if(b&1){
            res=res*a;
        }
        b>>=1;
        a=a*a;
    }
    return res;
}

void sol() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<"Bob\n";
        return ;
    }
    bool f=true;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            f=false;
            break;
        }
    }
    if(f){
        cout<<"Bob\n";
        return ;
    }

    int number=0;
    for(int i=0;i<n;i++){
        int cnt=0,cpy=a[i];
        bool ff=true;
        // int ori;
        for(int j=2;j*j<=cpy;j++){
            int tot=0;
            if(cpy%j==0){
                cnt++;
                while(cpy%j==0){cpy/=j;tot++;}
                if(tot>1) ff=false;
                if(ksm(j,tot)==a[i]){
                    a[i]=j;
                }
            }
        }
        if(cpy>1) cnt++;
        if(cnt>1){
            cout<<"Alice\n";
            return ;
        }else if(ff){
            number++;
        }
    }
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            cout<<"Alice\n";
            return ;
        }
    }
    if(number==n) cout<<"Alice\n";
    else cout<<"Bob\n";
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