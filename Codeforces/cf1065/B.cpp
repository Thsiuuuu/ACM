#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]==-1&&a[n]==-1){
        a[1]=a[n]=0;
    }else if(a[1]==-1||a[n]==-1){
        a[1]=a[n]=max(a[1],a[n]);
    }
    cout<<abs(a[1]-a[n])<<'\n';
    for(int i=1;i<=n;i++){
        if(a[i]==-1){
            cout<<"0 ";
        }else{
            cout<<a[i]<<" ";
        }
    }
    cout<<'\n';
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