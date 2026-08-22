#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    cin>>n;
    vector<int> a(n);
    int cnt=n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=0;
    for(int i=0;i<n;i++){
        if(a[i]!=cnt){
            l=i;
            break;
        }
        cnt--;
    }
    for(int i=l;i<n;i++){
        if(a[i]==cnt){
            r=i;
            break;
        }
    }
    reverse(a.begin()+l,a.begin()+r+1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}