#include <bits/stdc++.h>
using namespace std;

void sol(){
    int l,r;
    int n;
    cin>>n;
    vector<int> num(n+1);
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(num[i]==1) l=i;
        else if(num[i]==n) r=i;
    }
    string x;
    cin>>x;
    x=' '+x;
    if(x[1]=='1'||x[n]=='1'||x[l]=='1'||x[r]=='1'){
        cout<<"-1\n";
    }else{
        cout<<"5\n";
        cout<<1<<" "<<l<<'\n';
        cout<<1<<" "<<r<<'\n';
        cout<<min(l,r)<<" "<<max(l,r)<<'\n';
        cout<<l<<" "<<n<<'\n';
        cout<<r<<" "<<n<<'\n';
    }
    
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