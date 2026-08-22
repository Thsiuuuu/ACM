#include <bits/stdc++.h>
using namespace std;

string check(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,114514);
    int x=dis(gen);
    int y=dis(gen);
    int mid=(x|y)-(x&y);
    if(mid==(x^y)){
        return "Yes\n";
    }else{
        return "No\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        string ans=check();
        cout<<ans;
        if(ans=="No\n"){
            break;
        }
    }
    return 0;
}