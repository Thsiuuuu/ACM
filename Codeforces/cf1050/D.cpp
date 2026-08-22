#include <bits/stdc++.h>
using namespace std;

using ll=long long ;

void sol(){
    ll sum=0;
    ll n;
    cin>>n;
    vector<ll> num;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x%2==0) sum+=x;
        else num.push_back(x);
    }
    if(num.size()==0){cout<<"0\n";}
    else{
        sort(num.begin(),num.end(),greater<ll>());
        for(int i=0;i<=(num.size()-1)/2;i++){
            sum+=num[i];
        }
        cout<<sum<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}