#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    int n,k;cin>>n>>k;
    set<int> st;
    if(n>=k) cout<<"-1\n";
    else{
        ll cur=1,s=0;
        for(int i=1;i<=n;i++){
            while((s+cur)%k==0||st.find((s+cur)%k)!=st.end()) cur++;
            s+=cur;st.insert(s%k);
            cout<<cur<<" ";
            cur++;
        }
        cout<<'\n';
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