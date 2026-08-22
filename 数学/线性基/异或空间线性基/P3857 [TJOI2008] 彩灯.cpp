#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<ll> a(m+1,0);
    string s;
    for(int i=1;i<=m;i++){
        cin>>s;
        ll sum=0;
        for(int j=0;j<n;j++){
            if(s[j]=='O') sum+=(1ll<<(n-j-1));
        }
        a[i]=sum;
    }
    // for(int i=1;i<=m;i++){
    //     cout<<a[i]<<'\n';
    // }
    int row=1;
    for(int col=n-1;~col&&row<=m;col--){
        for(int i=row;i<=m;i++){
            if((a[i]>>col)&1){
                swap(a[row],a[i]);
                break;
            }
        }
        if(!((a[row]>>col)&1)) continue;
        for(int i=1;i<=m;i++){
            if(i==row) continue;
            if((a[i]>>col)&1) a[i]^=a[row];
        }
        row++;
    }
    row--;
    cout<<(1ll<<row)%2008;
    return 0;
}