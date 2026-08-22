#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long


signed main(){
    
    int n;
    cin>>n;
    vector<int>number(n);
    for(int i=0;i<n;i++) cin>>number[i];

    int q,cnt=0;
    cin>>q;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        if(binary_search(number.begin(),number.end(),x)) cnt++;
    }
    cout<<cnt;
    return 0;

}