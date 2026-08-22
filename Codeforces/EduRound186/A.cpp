#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    bool f1=false,f2=false;
    string s;
    int n;
    cin>>n>>s;
    // for(int i=0;i+3<n;i++){
    //     if(s.substr(i,4)=="2026"){
    //         f2=true;
    //     }else if(s.substr(i,4)=="2025"){
    //         f1=true;
    //     }
    // }
    // if(f2||(!f1)){
    //     cout<<"0\n";
    // }else cout<<"1\n";  
    if(s.find("2025")==string::npos||s.find("2026")!=string::npos){
        cout<<"0\n";
    }else{
        cout<<"1\n";
    }
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