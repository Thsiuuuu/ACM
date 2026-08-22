#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*

    这个题当时做的时候没有建立数学模型
    如果一个结果不是很好找的话，可以考虑通过建立数学模型的角度进行描述
    比如说把所有的a都放到某一个位置开始的一段，所需要的代价是多少
    然后这个式子写出来可以发现答案正好是中位数

*/
#define int  long long 
int t;


int cost(vector<int>&a){

    // for(int i=0;i<a.size();i++){
    //     a[i]=a[i]-i;
    //     // cout<<a[i]<<" ";
    // }
    // // cout<<'\n';
    int l=a.size();
    int ans=0;
    for(int x:a){
        ans+=abs(x-a[l/2]);
    }
    return ans;
}

void sol(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a,b;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            a.push_back(i-a.size());
        }else{
            b.push_back(i-b.size());
        }
    }

    cout<<min(cost(a),cost(b))<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}