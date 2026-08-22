    #include <bits/stdc++.h>
    using namespace std;
    #define int long long 

    void sol(){
        int n;
        cin>>n;
        if(n<=2){
            cout<<"0\n";
        }
        cout<<(n-1)/2<<'\n';
    }
    signed main(){
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);

        int t;
        cin>>t;
        while(t--){
            sol();
        }
    }