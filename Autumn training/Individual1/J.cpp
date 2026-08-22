#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void sol(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    int g=(int)0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        g=gcd(g,a[i]);
    }
    if(g==1){
        cout<<"0\n";
    }else{
        int g1=(int)0;
        for(int i=1;i<=n-1;i++){
            g1=gcd(g1,a[i]);
        }
        g1=gcd(g1,gcd(a[n],n));
        if(g1==1){cout<<"1\n";}
        else{
            g1=(int)0;
            for(int i=1;i<=n-2;i++){
                g1=gcd(g1,a[i]);
            }
            g1=gcd(g1,a[n]);
            g1=gcd(g1,gcd(a[n-1],n-1));
            if(g1==1){cout<<"2\n";}
            else cout<<"3\n";
        }
    }
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}