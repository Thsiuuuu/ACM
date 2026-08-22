#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    int n;cin>>n;
    vector<int> a(n+1,0),stk(n+10,0);
    int top=0,ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stk[++top]=1;
    for(int i=2;i<=n;i++){
        while(top>1&&a[stk[top]]>a[i]) top--,ans++;
        stk[++top]=i;
    }
    cout<<ans<<'\n';
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