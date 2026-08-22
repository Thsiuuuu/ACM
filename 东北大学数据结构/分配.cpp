#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#define endl "\n"
using namespace std;

#define int long long

bool check(const vector<int>& w,int k,int p){
    
    int number=1;
    int cur=0;
    for(int weight:w){
        if(cur+weight>p){
            number++;
            cur=weight;
        }else cur+=weight;
        if(number>k) return false;
    }

    return true;
}


signed main(){

    int n,k;
    cin>>n>>k;
    vector<int> w(n);
    int sum=0;
    int mx=0;

    for(int i=0;i<n;i++){
        cin>>w[i];
        sum+=w[i];
        mx=max(mx,w[i]);
    }

    int l=mx;
    int r=sum;

    while(l<r){
        int mid=(l+r)/2;
        if(check(w,k,mid)) r=mid;
        else l=mid+1;
    }

    cout<<l<<endl;
    return 0;
}