#include <bits/stdc++.h>
using namespace std;
/*
    /\_/\
    ( =o.o= ) *
    / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>

ll pw[18];
void init(){
    pw[0]=1;
    for(int i=1;i<=17;i++) pw[i]=pw[i-1]*10;
}

void sol() {
    ll a;
    int n;
    cin>>a>>n;
    vector<ll> d(n,0);
    vector<bool> is(11,0);
    for(int i=0;i<n;i++){
        cin>>d[i];
        is[d[i]]=1;
    }
    ll Mx=0,Mn=0;
    string tmp=to_string(a);
    if(n==1&&d[0]==0){
        cout<<a<<'\n';
        return ;
    }
    // ll An0=0;
    for(int i=1;i<tmp.size();i++){
        Mx=Mx*10+d[n-1],Mn=Mn*10+d[0];
        // An0=An0*10+(d[0]
        //     // ?d[0]:d[1]
        // );
    }
    ll ans=Mn*10+(d[0]?d[0]:d[1])*pw[tmp.size()]+(d[0])-a;
    if(a<10&&d[0]!=0){
        // cout<<"hel\n";
    }else{
        ans=min(ans,a-Mx);
    }
    for(int i=0;i<tmp.size();i++){
        int cur=tmp[i]-'0';
        // cout<<Mn<<'\n';
        for(int x=cur+1;x<10;x++){
            if(is[x]){
                // cout<<i<<" "<<pw[tmp.size()-1-i]*x+Mn<<'\n';
                ans=min(pw[tmp.size()-1-i]*x+Mn-stoll(tmp.substr(i,tmp.size()-i)),ans);
                break;
            }
        }
        for(int x=cur-1;x>=0;x--){
            if(is[x]){
                // cout<<i<<" "<<pw[tmp.size()-1-i]*x+Mx<<'\n';
                ans=min(stoll(tmp.substr(i,tmp.size()-i))-pw[tmp.size()-1-i]*x-Mx,ans);
                // cout<<ans<<'\n';
                break;
            }
        }
        if(!is[cur]) break;
        if(i==tmp.size()-1) ans=0;
        Mx/=10,Mn/=10;
        // cout<<"hel\n";
    }
    cout<<ans<<'\n';
    


    // int Mx=-1,Mn=11;
    // string tmp=to_string(a);
    // for(int i=0;i<tmp.size();i++){
    //     Mx=max(Mx,tmp[i]-'0');
    //     Mn=min(Mn,tmp[i]-'0');
    // }
    // ll ans=1e18;
    // if(tmp.size()>1&&!(n==1&&d[n-1]==0)){
    //     ll num=0;
    //     for(int i=0;i<tmp.size();i++){
    //         if(i){
    //             num*=10;
    //             num+=d[n-1];
    //         }
    //     }
    //     ans=min(ans,a-num);
    // }
    // ll num=0;
    // for(int i=0;i<tmp.size()+1;i++){
    //     num*=10;
    //     num+=d[0];
    // }
    // ans=min(ans,num-a);
    // num=0;
    // if(d[n-1]>=Mx){
    //     bool f=true;
    //     for(int i=0;i<tmp.size();i++){
    //         num*=10;
    //         if(!is[tmp[i]-'0']&&(f)){
    //             for(int j=tmp[i]-'0'+1;j<=9;j++){
    //                 if(is[j]){
    //                     num+=j;
    //                     break;
    //                 }
    //             }
    //             f=false;
    //         }else if(f){
    //             num+=(tmp[i]-'0');
    //         }else{
    //             num+=d[0];
    //         }
    //     }
    //     ans=min(ans,num-a);
    // }
    // num=0;
    // if(d[0]<=Mn){
    //     bool f=true;
    //     for(int i=0;i<tmp.size();i++){
    //         num*=10;
    //         if(!is[tmp[i]-'0']&&(f)){
    //             for(int j=tmp[i]-'0'-1;j>=0;j--){
    //                 if(is[j]){
    //                     num+=j;
    //                     break;
    //                 }
    //             }
    //             f=false;
    //         }else if(f){
    //             num+=tmp[i]-'0';
    //         }else{
    //             num+=d[n-1];
    //         }
    //     }
    //     ans=min(ans,a-num);
    // }
    // cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;

    init();
    while (t--) {
        sol();
    }
    return 0;
}