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
ll pw[13];
void init(){
    pw[0]=1;
    for(int i=1;i<10;i++) pw[i]=pw[i-1]*10;
}
void sol() {
    int n;cin>>n;
    vector<string> s1,s2;
    // if(n==1){
    //     cout<<"0 0 0\n";
    //     return ;
    // }
    for(int i=0;i<n;i++){
        string p;cin>>p;
        s1.push_back(p);
        cin>>p;
        s2.push_back(p);
    }   
    for(int sum=1;sum<=7;sum++){
        for(int a=0;a<=sum;a++){
            for(int b=0;b<=sum-a;b++){
                int c=sum-b-a;
                if(a==0&&b==0&&c==0) continue;
                bool f=true;
                unordered_map<string,int> mp;
                for(int i=0;i<n;i++){
                    string fin=s1[i].substr(0,a)+s2[i].substr(0,b);
                    if(mp[fin]<pw[c]){
                        mp[fin]++;
                    }else{
                        f=false;
                        break;
                    }
                }
                if(f){
                    cout<<a<<" "<<b<<" "<<c<<'\n';
                    return ;
                }
            }
        }
    }

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