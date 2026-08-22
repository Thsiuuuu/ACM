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
char mp[52][52];
bool ck1(int cur,int up,int down){
    bool f=true;
    for(int i=up;i<=down;i++) f&=(mp[i][cur]=='.');
    return f;
}

bool ck2(int cur,int left,int right)    {
    bool f=true;
    for(int i=left;i<=right;i++) f&=(mp[cur][i]=='.');
    return f;
}
void sol() {
    int h,w;cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>mp[i][j];
        }
    }
    int left=0,right=w-1,up=0,down=h-1;
    // for(int j=up;j<=down;j++){
    //     for(int i=left;i<=right;i++){
    //         cout<<mp[i][j];
    //     }
    //     cout<<'\n';
    // }
    while(left<=right&&up<=down){
        bool is=false;
        if(ck1(left,up,down)){
            left++;
            is=true;
        }
        if(ck1(right,up,down)){
            right--;
            is=true;
        }
        if(ck2(up,left,right)){
            up++;
            is=true;
        }
        if(ck2(down,left,right)){
            down--;
            is=true;
        }
        if(!is) break;
    }
    // cout<<up<<" "<<down<<'\n';
    // cout<<left<<" "<<right<<'\n';
    for(int i=up;i<=down;i++){
        for(int j=left;j<=right;j++){
            cout<<mp[i][j];
        }
        cout<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}