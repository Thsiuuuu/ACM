#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
const ll mod=998244353;
const int N=2e5+10;
ll f[N];

void init(){
    f[0]=f[1]=1;
    for(int i=2;i<=N-10;i++){
        f[i]=f[i-1]*i%mod;
    }
}

void sol() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(b[0]==1){
        cout<<f[n]<<'\n';
    }else{
        int m=0;
        for(int i=0;i<n;i++){
            if(a[i]==i+1){
                m++;
            }
        }
        cout<<f[n-m]*f[m]%mod<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    init();
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}