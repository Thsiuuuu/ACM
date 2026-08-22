#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    cin>>n;
    vector<int>temp(n+1),p(n+1);
    int dis=-1;
    iota(temp.begin()+1,temp.end(),1);
    for(int i=1;i<=n;i++){
        cin>>p[i];
        if(p[i]>i){
            dis=max(dis,p[i]-i+1);
        }
    }
    if(dis==-1){
        cout<<"1";
    }else cout<<dis;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t
    while (t--) {
        sol();
    }
    return 0;
}