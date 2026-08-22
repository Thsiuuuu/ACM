#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int t;


// int gcd(int a,int b){
//     return !b?a:gcd(b,a%b);
// }

void sol(){
    int n;
    set<int,greater<int>> st;
    cin>>n;
    int g=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()*2-1<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}