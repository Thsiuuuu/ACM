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

struct node{
    string s;
    int tot;
};

vector<string> all;
void init(){
    for(int i=0;i<=9999;i++){
        string s=to_string(i);
        s.insert(s.begin(),4-s.size(),'0');
        all.push_back(s);
    }
}

void sol() {
    int n;
    cin>>n;
    vector<node> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].s>>a[i].tot;
    }
    for(string s:all){
        bool f=true;
        // cout<<s<<'\n';
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<4;j++){
                if(a[i].s[j]==s[j]) cnt++;
            }
            if(cnt!=a[i].tot){
                f=false;
                break;
            }
        }
        if(f){
            cout<<s<<'\n';
            return ;
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