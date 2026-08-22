#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1),preA(n+1,0),preB(n+1,0),pre(n+1,0),suf(n+1,0);
    
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    for(int i=1;i<=n;i++){
        if(a[i]^b[i]){
            if(i&1) preA[i]++;
            else preB[i]++;
        }
        preA[i]+=preA[i-1];
        preB[i]+=preB[i-1];
        pre[i]=pre[i-1]^a[i];
    }
    for(int i=n;i>=1;i--){
        
    }
    int flag=-1;
    for(int i=n;i>=1;i--){
        if(a[i]^b[i]){
            flag=(i&1);
            break;
        }
    }
    bool f=false;//1前赢
    if(flag==-1){
        f=(pre&1);
    }else{

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