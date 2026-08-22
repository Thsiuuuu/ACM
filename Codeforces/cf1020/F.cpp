#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    int n;
    string s;
    cin>>n>>s;
    s=' '+s;
    
    ll f=1,up=0,down=0,ans=0;
    for(int i=1;i<=n;i++){
        if(i==1){
            if(s[i]=='0') down+=n-1;
            else up+=1;
        }else{
            string T;
            T.push_back(s[i-1]);
            T.push_back(s[i]);
            if(T=="00"){
                up+=i-1;
                down+=n-i;
            }else if(T=="10"){
                up+=i-1;
                down+=n-i;
            }else if(T=="11"){
                up=1;
                down=0;
            }else if(T=="01"){
                up=down+1;
                down=0;
            }
        }
        // cout<<up<<" "<<down<<'\n';
        ans=max(ans,down);
        ans=max(ans,up);
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