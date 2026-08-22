#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
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
const int N=1e4+10;
int sg[N+2];
void ck(){
    sg[0]=0,sg[1]=1,sg[2]=0,sg[3]=1;
    for(int i=4;i<=N;i++){
        set<int> s;
        s.insert(sg[i-1]);
        s.insert(sg[i-3]);
        s.insert(sg[i-4]);
        for(int x=0;;x++){
            if(s.find(x)==s.end()){
                sg[i]=x;
                break;
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(sg[i]==0){
            cout<<i<<" "<<sg[i]<<'\n';
        }
    }
}
void sol() {
    // ck();
    int n;cin>>n;
    if(n%7==2||n%7==0){
        cout<<"ice\n";
    }else{
        cout<<"Orange\n";
    }
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