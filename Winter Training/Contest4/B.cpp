#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    string s;
    cin>>n>>s;
    string cpy;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(i+1<n&&s[i+1]==s[i]&&s[i+1]=='1'){
            int j=i;
            while(j+1<n&&s[j+1]==s[i]){
                ans++;
                j++;
            }
            i=j;
            cpy.push_back('1');
        }else{
            cpy.push_back(s[i]);
        }
    }
    // cout<<cpy<<'\n';
    
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