#include <bits/stdc++.h>
using namespace std;
/*



*/

#define ll long long 
const ll mod=998244353;
ll numa[5],numb[5],p[8];

// void cal(int a,int b){

// }

ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}

// ll operator*(ll a,ll b){
//     return (ll)a*b%mod;
// }

ll cal(ll number){
    if(number==0){
        return p[1]*p[2]%mod*p[3]%mod*(100-p[4])%mod*p[5]%mod*p[6]%mod*p[7]%mod;
    }else if(number==1){
        return (100-p[1])%mod*(100-p[2])%mod*p[3]%mod*(100-p[4])%mod*(100-p[5])%mod*p[6]%mod*(100-p[7])%mod;
    }else if(number==2){
        return p[1]*(100-p[2])%mod*p[3]%mod*p[4]%mod*p[5]%mod*(100-p[6])%mod*p[7]%mod;
    }else if(number==3){
        return p[1]*(100-p[2])%mod*p[3]%mod*p[4]%mod*(100-p[5])%mod*p[6]%mod*p[7]%mod;
    }else if(number==4){
        return (100-p[1])*p[2]%mod*p[3]%mod*p[4]%mod*(100-p[5])%mod*p[6]%mod*(100-p[7])%mod;
    }else if(number==5){
        return p[1]*p[2]%mod*(100-p[3])%mod*p[4]%mod*(100-p[5])%mod*p[6]%mod*p[7]%mod;
    }else if(number==6){
        return p[1]*p[2]%mod*(100-p[3])%mod*p[4]%mod*p[5]%mod*p[6]%mod*p[7]%mod;
    }else if(number==7){
        return p[1]*(100-p[2])%mod*p[3]%mod*(100-p[4])%mod*(100-p[5])%mod*p[6]%mod*(100-p[7])%mod;
    }else if(number==8){
        return p[1]*p[2]%mod*p[3]%mod*p[4]%mod*p[5]%mod*p[6]%mod*p[7]%mod;
    }else if(number==9){
        return p[1]*p[2]%mod*p[3]%mod*p[4]%mod*(100-p[5])%mod*p[6]%mod*p[7]%mod;
    }else{
        return 0ll;
    }
}


void sol() {
    int c;
    cin>>c;
    for(int i=1;i<=7;i++){
        cin>>p[i];
    }
    ll sum=0;
    for(int a=0;a<=c;a++){
        int b=c-a;
        int ori=1;
        ll ans=1;
        for(int i=1;i<=4;i++){
            numa[i]=a%(ori*10)/ori;
            numb[i]=b%(ori*10)/ori;
            ori*=10;
        }
        for(int i=1;i<=4;i++){
            ans=ans*cal(numa[i])%mod*qmi(100,7*mod-14)%mod;
            ans=ans*cal(numb[i])%mod*qmi(100,7*mod-14)%mod;
        }
        sum=(sum+ans)%mod;
    }
    cout<<sum<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}