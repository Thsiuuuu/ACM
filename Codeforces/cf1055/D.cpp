#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long

ll sub(int l,int r,vector<ll> &a){
    return a[r]-a[l-1];
}

void sol() {
    int n,q;
    cin>>n>>q;
    vector<ll> a(n+1),A(n+1,0),B(n+1,0),C(n+1,0),lg(n+1,0);

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        A[i]=A[i-1],B[i]=B[i-1];
        lg[i]=lg[i-1]+(ll)floorl(log2(a[i]));
        if(__builtin_popcount(a[i])==1) A[i]++;
        else if(__builtin_popcount(a[i])==2&&(a[i]&1)) B[i]++;
        C[i]=i-A[i]-B[i]; 
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<sub(l,r,lg)+sub(l,r,C)+sub(l,r,B)-(sub(l,r,B)+1)/2<<'\n';
    }

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