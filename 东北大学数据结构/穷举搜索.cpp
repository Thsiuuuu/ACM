#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#include <unordered_set>

#define endl "\n"
using namespace std;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    unordered_set<int> sums;

    for(int mask=1;mask<(1<<n);mask++){
        int sum=0;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)) sum+=a[i];
        }
        sums.insert(sum);
    }

    int q;
    cin>>q;
    while(q--){
        int m;
        cin>>m;
        cout<<(sums.count(m)?"yes\n":"no\n");
    }
    return 0;
}