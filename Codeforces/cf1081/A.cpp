#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    string s;
    cin>>n>>s;
    int number=0;
    bool f=true;
    for(int i=0;i<n;i++){
        int cur=i;
        number++;
        while(cur<n&&s[cur]==s[i]){
            cur++;
        }
        if(cur>i+1&&f){
            number++;
            f=false;
        }
        i=cur-1;
    }
    if(s[0]==s[n-1]&&(!f)) number--;
    cout<<number<<'\n';
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