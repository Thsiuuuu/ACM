#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    cin>>n;
    vector<int> p(n+1),a(n+1),pos(n+1),vis(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>p[i];
        pos[p[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int r=1;
    for(int i=1;i<=n;i++){
        if(pos[a[i]]>=r){
            // vis[a[i]]=1;
            r=max(r,pos[a[i]]);
        }else{
            cout<<"no\n";
            return ;
        }
        // else if(pos[a[i]]<=i&&pos[a[i]]>=r){
        //     if(p[r]!=a[i]&&vis[a[i]]==0){
        //         while(r<=i&&p[r]!=a[i]){
        //             vis[p[r]]=1;
        //             r++;
        //         }
        //     }else if(p[r]!=a[i]&&vis[a[i]]){
        //         cout<<"no\n";
        //         return ;
        //     }
        // }
        
    }
    cout<<"yes\n";
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