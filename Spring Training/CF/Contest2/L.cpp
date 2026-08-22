#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

int val(char c){
    if(c>='0'&&c<='9') return (int)(c-'0');
    else return 10+(int)(c-'A');
}

void yes(){
    cout<<"YES\n";
}

void no(){
    cout<<"NO\n";
}

void debug(){
    cout<<"hel\n";
}

void sol() {
    string a;
    cin>>a;
    
    // debug();
    reverse(a.begin(),a.end());
    if(a.size()==1){
        if(a=="9"||a=="0"){
            yes();
        }else{
            no();
        }
    }
    else{
        if(
            (val(a[0])+15*val(a[1]))%9==0||
            (val(a[1])+15*val(a[0]))%9==0
        ) yes();
        else{
            bool f=false;
            for(int i=2;i<a.size();i++){
                if(
                    (val(a[0])+15*val(a[i]))%9==0||
                    (val(a[i])+15*val(a[1]))%9==0
                ){
                    f=true;
                    break;
                }
            }
            if(f) yes();
            else no();
        }
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