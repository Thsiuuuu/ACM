#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> tik(n);
    for(int i=0;i<n;i++) cin>>tik[i];

    sort(tik.begin(),tik.end());
    while(m--){
        int t;
        cin>>t;
        auto it=upper_bound(tik.begin(),tik.end(),t);
        if(it!=tik.begin()){
            --it;
            cout<<*it<<"\n";
            tik.erase(it);
        }else cout<<"-1\n";
    }

    return 0;
    
    
}