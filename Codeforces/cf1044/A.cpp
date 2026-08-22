#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n;
    cin>>n;
    vector<int> a(n),num(110,0);
    bool f1=false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        num[a[i]]++;
        if(num[a[i]]>1) f1=true;
    }
    cout<<((f1)?"yes":"no")<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}