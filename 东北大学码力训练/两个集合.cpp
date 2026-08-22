#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define int long long 



signed main(){

    int n;
    cin>>n;
    int sum=n*(n+1)/2;
    if(sum%2!=0){
        cout<<"NO\n";
        return 0;
    }
    int obj=sum/2;
    vector<int> set1,set2;
    vector<bool> st(10000001,false);
    int s=0;
    for(int i=n;i>=1;i--){
        if(s+i<=obj){
            set1.push_back(i);
            s+=i;
            st[i]=true;
            if(s==obj) break;
        }
    }
    for(int i=1;i<=n;i++){
        if(!st[i]) set2.push_back(i);
    }
    cout<<"YES\n";
    cout<<set1.size()<<"\n";
    for(auto number:set1) cout<<number<<" ";
    cout<<"\n";
    cout<<set2.size()<<"\n";
    for(auto number:set2) cout<<number<<" ";
    cout<<"\n";
    return 0;

}