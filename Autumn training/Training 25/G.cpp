#include <bits/stdc++.h>
using namespace std;

#define int long long 

/*


    错误点：不一定是2的次幂才可以
    使字典序最小的方法：交换相邻两个数
    什么时候不行：交换之后异或和还是为0，无力回天

*/

int judge(int i){
    int pw=1;
    for(int j=0;j<=20;j++){
        if(pw==i){
            return 1;
        }
        pw*=2;
        if(pw>i){
            break;
        }
    }
    return 0;
}


void sol(){
    int n;
    cin>>n;
    

    int pw=1;

    vector<int> ans;
    int tri1=0;
    for(int i=0;i<=n-1;i++){
        if((tri1==i)&&(i+1)<=n-1){
            ans.push_back(i+1);
            ans.push_back(i);
            tri1^=i;
            tri1^=(i+1);
            i++;
            
        }else if((tri1==i)&&(i+1)>n-1){
            cout<<"impossible\n";
            return ;
        }else{
            ans.push_back(i);
            tri1^=i;
        }
    }

    for(int i:ans){
        cout<<i<<" ";
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