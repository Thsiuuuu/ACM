#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
void sol() {
    int n;cin>>n;
    vector<ll> a(n),last(n+1,-1);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n<=3){
        cout<<"yes\n";
        return ;
    }
    vector<ll> tmp=a;
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    int cnt=0;
    map<ll,int> mp;
    for(int i=0;i<tmp.size();i++){
        mp[tmp[i]]=cnt++;
    }
    for(int i=0;i<n;i++){
        a[i]=mp[a[i]];
    }
    cnt=0;
    vector<int> tx(2);
    for(int i=0;i<n;i++){
        if(last[a[i]]!=-1&&i-last[a[i]]>2){
            cout<<"No\n";
            return ;
        }else if(last[a[i]]!=-1){
            cnt++;
            // if(cnt>2){
            //     cout<<"NO\n";
            //     return ;
            // }
            if(cnt<=2){
                tx[cnt-1]=a[i];
            }
            // int j=i;
            // while(j<n&&a[j]==a[i]){
            //     j++;
            // }
            // last[a[i]]=j-1;
            // i=j-1;
        }else{
            int j=i;
            while(j<n&&a[j]==a[i]){
                j++;
            }
            last[a[i]]=j-1;
            i=j-1;
        }
    }
    
    if(cnt==0||
        (a[last[tx[0]]+1]==tx[1]&&a[last[tx[1]]+1]==tx[0])
    ){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
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