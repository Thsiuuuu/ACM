#include <bits/stdc++.h>
using namespace std;

#define int long long 
/*

    分两段
    回到原点，一次
    如果回到原点之后能够再次回到原点，是死循环
    否则无法回到原点

*/

void sol(){

    int n,x,k;
    cin>>n>>x>>k;
    string s;
    cin>>s;
    int cnt1=0,cnt2=0,st1=x,st2=0;
    bool f1=false,f2=false;
    for(int i=0;i<s.size();i++){
        if(f1&&f2) break;
        if(s[i]=='L'){
            st1--;
            st2--;
        }
        if(s[i]=='R'){
            st1++;
            st2++;
        }
        if(!f1) cnt1++;
        if(!f2) cnt2++;
        if(st1==0){
            f1=true;
        }
        if(st2==0){
            f2=true;
        }
    }
    if(!f1){
        cout<<"0\n";
    }else{
        int num=k-cnt1;
        cout<<(1ll+((!f2)?(0ll):(num/cnt2)))<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}