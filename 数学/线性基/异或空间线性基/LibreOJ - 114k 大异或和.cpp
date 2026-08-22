#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long 
#define ll long long 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n,m;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int row=1;
    for(int col=63;~col&&row<=n;--col){
        for(int i=row;i<=n;i++){
            if((a[i]>>col)&1){
                swap(a[row],a[i]);
                break;
            }
        }
        if(((a[row]>>col)&1)==0) continue;
        for(int i=1;i<=n;i++){
            if(i==row) continue;
            if((a[i]>>col)&1) a[i]^=a[row];
        }
        row++;
    }
    row--;
    cin>>m;
    while(m--){
        ll k;cin>>k;
        if(row^n){
            k--;
        }
        if((k)>=(1ull<<row)) cout<<"-1\n";
        else{
            ull ans=0;
            for(int i=row,j=0;i>=1&&j<64;j++,i--){
                if(((k)>>j)&1) ans^=a[i];
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}