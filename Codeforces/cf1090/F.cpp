#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
void sol() {
    int x,y;
    cin>>x>>y;
    if(y<x) cout<<"no\n";
    else{
        if(((x+y)&1)&&y==0) cout<<"no\n";
        else if((x+y)%2==0&&(x==0||y==0)) cout<<"no\n";
        else{
            cout<<"yes\n";
            if((x+y)&1) y--;
            else x--;
            int i=2;
            while(y>x){
                cout<<1<<" "<<i<<'\n';
                y--;
                i++;
            }
            while(y>0){
                cout<<1<<" "<<i<<'\n';
                cout<<i<<" "<<(i+1)<<'\n';
                i+=2;
                y--,x--;
            }
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