#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>


using namespace std;

#define int long long 

int num[51];

void sol(){

    int n;
    cin>>n;
    vector<int> a(n);

    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++){
        cin>>a[i];
        num[a[i]]++;
    }
    int sum=0;
    if(num[0]){
        int cnt=num[0]/2;
        sum+=(cnt*2);
        num[1]+=(num[0]%2);
    }
    for(int i=1;i<=50;i++){
        sum+=(num[i]*i);
    }
    cout<<sum<<"\n";

}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int t;
    cin>>t;
    while(t--)
        sol();

}