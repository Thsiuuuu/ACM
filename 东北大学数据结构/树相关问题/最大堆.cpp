#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#define int long long
void maxHeapify(vector<int>&a,int h,int i){
    while (true)
    {
        int left=2*i;
        int right=2*i+1;
        int mx=i;
        if(left<=h&&a[left]>a[mx]) mx=left;
        if(right<=h&&a[right]>a[mx]) mx=right;

        if(mx==i) break;

        swap(a[i],a[mx]);
        i=mx;
        /* code */
    }
    
}


void buildMaxHeap(vector<int>& a,int h){
    for(int i=h/2;i>=1;i--) maxHeapify(a,h,i);
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int h;
    cin>>h;

    vector<int> a(h+1);
    for(int i=1;i<=h;i++) cin>>a[i];

    buildMaxHeap(a,h);

    cout<<" ";
    for(int i=1;i<=h;i++){
        if(i>1) cout<<" ";
        cout<<a[i];
    }

    return 0;
}