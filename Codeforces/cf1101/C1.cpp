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
void sol() {
    ll n,x,s;
    cin>>n>>x>>s;
    string u;
    cin>>u;
    ll ans=0;
    int rem=0,have=0,cur=1,num=0;
    int base=0;
    //rem多余A,have有几桌,cur现在第几桌,num第几个
    for(int i=0;i<u.size();i++){
        if(u[i]=='I'&&have<x){
            if(have==0) num=1;
            else if(num==s&&cur==have){
                num=1;
                cur++;
            }
            have++;
            ans++;
        }else if(u[i]=='E'){
            if(have==0) continue;
            if(num<s){
                num++;
                ans++;
            }else if(num==s){
                if(cur<have&&s>1){
                    cur++;
                    num=2;
                    ans++;
                }else if(rem&&cur<x){
                    cur++;
                    rem--;
                    ans++;
                    have++;
                    num=1;
                }
            }
        }else if(u[i]=='A'){
            if(have==0){
                num++;
                have++;
                ans++;
            }else{
                if(num<s){
                    num++;
                    rem++;
                    ans++;
                }else if(num==s){
                    if(cur<have&&s>1){   
                        rem++;
                        ans++;
                        num=2;
                        cur++;
                    }else if((cur==have
                        // ||s==1
                    )
                        &&have<x){
                        ans++;
                        num=1;
                        cur++;
                        have++;
                    }
                }
            }
        }
        // cout<<i<<"\n";
        // cout<<u[i]<<'\n';
        // cout<<cur<<" "<<have<<" "<<num<<" "<<rem<<" "<<ans<<'\n';
    }
    cout<<ans<<'\n';
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