#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 

int add(int i,int n){
    return (i+1<=n)?(i+1):1;
}

int sub(int i,int n){
    return (i-1>0)?(i-1):n;
}


void sol() {
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<ll>> f(n+1,vector<ll>(n+1,0));
    for(int len=3;len<=n;len++){
        // cout<<"len:"<<len<<'\n';
        for(int i=1;i<=n;i++){
            int j=(i+len-1);
            if(j>n)   j=j%n;
            // cout<<i<<" "<<j<<'\n';
            f[i][j]=max({f[i][sub(j,n)],f[add(i,n)][j],f[i][j]});
            for(int k=i+1,tot=3;tot<=len;tot++){
                ll sum=0;
                if(k>n) k=k%n;
                if(tot>3) sum+=f[add(i,n)][sub(k,n)];
                if(tot<len) sum+=f[add(k,n)][sub(j,n)];
                f[i][j]=max({f[i][j],sum+a[i]*a[k]*a[j],f[i][k]+f[add(k,n)][j]});
                k++;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';
    //     }
    // }
    cout<<f[1][n]<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}