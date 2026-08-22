#include <bits/stdc++.h>
using namespace std;
#define int long  long 
/*

    直接计算很乱
    考虑用数学式子对这个过程进行表达
    即存在(1+10^k)x=n
    即n%(1+10^k)==0,此时n%(1+10^k)=x
    k最多17位，从高向低枚举即可

*/

int qmi(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans*=a;
        }
        b>>=1;
        a*=a;
    }
    return ans;
}

const int temp=qmi(10,18);

void sol(){
    int n;
    cin>>n;

    int cur=temp;
    priority_queue<int,vector<int>,greater<int>> ans;
    for(int i=0;i<18;i++){
        if(n%(cur+1)==0){
            ans.push(n/(cur+1));
        }
        cur/=10;
    }
    cout<<ans.size()<<(ans.size()?'\n':' ');
    while(ans.size()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<'\n';
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