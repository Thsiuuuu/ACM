#include <bits/stdc++.h>
using namespace std;
/*

    唐氏错误,long long时左移用1ll

*/
#define int long long 
void sol() {
    int n,q;
    cin>>n>>q;
    int tot=0;
    for(int i=63;i>=0;i--){
        if(n>>i&1){
            tot=i;
            break;
        }
    }
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            cout<<"1\n";
            continue;
        }
        int level=0;
        for(int i=63;i>=0;i--){
            if(x>>i&1){
                level=i;
                break;
            }
        }
        if(level!=tot){
            cout<<(1ll<<level)<<'\n';
        }else{
            cout<<(n-((1ll<<level)-1))<<'\n';//用1ll!
        }
    }
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